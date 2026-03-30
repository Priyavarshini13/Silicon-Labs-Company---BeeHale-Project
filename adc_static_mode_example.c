#include "adc_static_mode_example.h"

#include <stdint.h>
#include <stdbool.h>

#include "rsi_debug.h"
#include "sl_adc_instances.h"
#include "sl_si91x_adc.h"
#include "sl_si91x_adc_common_config.h"

#define VREF        3.3f
#define ADC_MAX     4095.0f

#define CALIB_SAMPLES  20     // samples for baseline
#define GAS_OFFSET     0.5f   // threshold above baseline

static volatile bool data_ready = false;
static uint16_t adc_value;

static float baseline_voltage = 0.0f;
static bool calibrated = false;

/* ADC callback */
static void adc_callback(uint8_t ch, uint8_t event)
{
  (void)ch;

  if (event == SL_ADC_STATIC_MODE_EVENT) {
    data_ready = true;
  }
}

/* Simple delay */
void delay_ms(uint32_t ms)
{
  for (uint32_t i = 0; i < ms * 3000; i++) {
    __asm__("nop");
  }
}

/* INIT */
void adc_static_mode_example_init(void)
{
  sl_status_t status;

  sl_adc_channel_config.channel = SL_ADC_CHANNEL_1; // ULP_GPIO_1

  status = sl_si91x_adc_init(sl_adc_channel_config, sl_adc_config, VREF);

  DEBUGINIT();

  if (status != SL_STATUS_OK) {
    DEBUGOUT("ADC init failed\n");
    return;
  }

  DEBUGOUT("ADC Init OK\n");

  sl_si91x_adc_set_channel_configuration(sl_adc_channel_config, sl_adc_config);

  sl_si91x_adc_register_event_callback(adc_callback);

  sl_si91x_adc_start(sl_adc_config);

  DEBUGOUT("Warming up MQ2... wait 10 sec\n");
  delay_ms(10000);   // MQ2 warm-up
}

/* PROCESS */
void adc_static_mode_example_process_action(void)
{
  static int sample_count = 0;
  static float sum = 0;

  if (!data_ready)
    return;

  data_ready = false;

  if (sl_si91x_adc_read_data_static(sl_adc_channel_config,
                                    sl_adc_config,
                                    &adc_value) != SL_STATUS_OK) {
    DEBUGOUT("ADC read error\n");
    return;
  }

  float voltage = ((float)adc_value / ADC_MAX) * VREF;

  DEBUGOUT("Voltage: %.2f V\n", voltage);

  /* ============================
     🔹 CALIBRATION PHASE
  ============================ */
  if (!calibrated) {
    sum += voltage;
    sample_count++;

    DEBUGOUT("Calibrating... (%d/%d)\n", sample_count, CALIB_SAMPLES);

    if (sample_count >= CALIB_SAMPLES) {
      baseline_voltage = sum / CALIB_SAMPLES;
      calibrated = true;

      DEBUGOUT("Baseline: %.2f V\n", baseline_voltage);
      DEBUGOUT("Calibration DONE\n");
    }
  }
  else {
    /* ============================
       🔹 GAS DETECTION
    ============================ */

    if (voltage > (baseline_voltage + GAS_OFFSET)) {
      DEBUGOUT("⚠ GAS DETECTED!\n");
    } else {
      DEBUGOUT("SAFE\n");
    }
  }

  DEBUGOUT("----------------------\n");

  delay_ms(2000);   // 2 sec delay

  sl_si91x_adc_start(sl_adc_config);
}
