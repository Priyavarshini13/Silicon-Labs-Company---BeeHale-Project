#include "app.h"
#include "rsi_debug.h"
#include "sl_si91x_gpio.h"
#include "sl_i2c_instances.h"
#include "sl_si91x_i2c.h"
#include "sl_si91x_peripheral_i2c.h"

#define SI7021_ADDR  0x40
#define I2C_INSTANCE SL_ULP_I2C

#define LED_PIN  12   // UULP GPIO

static sl_i2c_config_t sl_i2c_config;

// Global values
float g_temperature = 0;
float g_humidity = 0;

/* Function Prototypes */
static void read_humidity(void);
static void read_temperature(void);
static void control_led(void);

/**********************************************************/
void app_init(void)
{
  sl_i2c_status_t status;

  DEBUGINIT();
  DEBUGOUT("SI7021 I2C Master Example\n");

  // I2C INIT
  sl_i2c_config = sl_i2c_i2c2_config;
  sl_i2c_config.mode = SL_I2C_LEADER_MODE;
  sl_i2c_config.transfer_type = SL_I2C_USING_INTERRUPT;
  sl_i2c_config.operating_mode = SL_I2C_STANDARD_MODE;

  status = sl_i2c_driver_init(I2C_INSTANCE, &sl_i2c_config);

  if (status == SL_I2C_SUCCESS)
  {
    DEBUGOUT("I2C Master Initialized\n");
    sl_i2c_driver_configure_fifo_threshold(I2C_INSTANCE, 0, 0);
  }
  else
  {
    DEBUGOUT("I2C Init Failed\n");
  }

  // ✅ CORRECTED GPIO INIT
  sl_si91x_gpio_set_uulp_npss_pin_mux(LED_PIN, 0);
  sl_si91x_gpio_set_uulp_npss_direction(LED_PIN, GPIO_OUTPUT);

  // Default OFF - Use the correct API
  // Try one of these alternatives:

  // Option A: If you need to write a specific value
  sl_si91x_gpio_set_uulp_npss_pin_value(LED_PIN, 0);  // Try this first

  // Option B: Or use clear to turn off
  // sl_si91x_gpio_clear_uulp_npss_pin(LED_PIN);
}

/**********************************************************/
void app_process_action(void)
{
  read_humidity();
  read_temperature();

  control_led();

  for(volatile uint32_t i = 0; i < 8000000; i++);
}

/**********************************************************/
static void read_humidity(void)
{
  uint8_t cmd = 0xF5;
  uint8_t rx_buf[3];
  uint16_t raw;
  sl_i2c_status_t status;

  status = sl_i2c_driver_send_data_blocking(I2C_INSTANCE,
                                            SI7021_ADDR,
                                            &cmd,
                                            1);

  if(status != SL_I2C_SUCCESS)
  {
    DEBUGOUT("Humidity Write Failed\n");
    return;
  }

  for(volatile uint32_t i = 0; i < 15000000; i++);

  do {
      status = sl_i2c_driver_receive_data_blocking(I2C_INSTANCE,
                                                   SI7021_ADDR,
                                                   rx_buf,
                                                   3);
  } while(status == SL_I2C_TIMEOUT);

  if(status != SL_I2C_SUCCESS)
  {
    DEBUGOUT("Humidity Read Failed\n");
    return;
  }

  raw = (rx_buf[0] << 8) | rx_buf[1];
  raw &= 0xFFFC;

  g_humidity = ((125.0 * raw) / 65536.0) - 6.0;

  DEBUGOUT("Humidity: %.2f %%\n", g_humidity);
}

/**********************************************************/
static void read_temperature(void)
{
  uint8_t cmd = 0xF3;
  uint8_t rx_buf[3];
  uint16_t raw;
  sl_i2c_status_t status;

  status = sl_i2c_driver_send_data_blocking(I2C_INSTANCE,
                                            SI7021_ADDR,
                                            &cmd,
                                            1);

  if(status != SL_I2C_SUCCESS)
  {
    DEBUGOUT("Temp Write Failed\n");
    return;
  }

  for(volatile uint32_t i = 0; i < 15000000; i++);

  do {
      status = sl_i2c_driver_receive_data_blocking(I2C_INSTANCE,
                                                   SI7021_ADDR,
                                                   rx_buf,
                                                   3);
  } while(status == SL_I2C_TIMEOUT);

  if(status != SL_I2C_SUCCESS)
  {
    DEBUGOUT("Temp Read Failed\n");
    return;
  }

  raw = (rx_buf[0] << 8) | rx_buf[1];
  raw &= 0xFFFC;

  g_temperature = ((175.72 * raw) / 65536.0) - 46.85;

  DEBUGOUT("Temperature: %.2f C\n\n", g_temperature);
}

/**********************************************************/
static void control_led(void)
{
  // Condition:
  // Temp < 30 OR Temp > 35
  // OR Humidity < 60 OR Humidity > 70

  if ((g_temperature > 35.0 || g_temperature < 30.0) ||
      (g_humidity < 60.0 || g_humidity > 70.0))
  {
    // ON - Use the correct API
    sl_si91x_gpio_set_uulp_npss_pin_value(LED_PIN, 1);  // Try this
    // OR
    // sl_si91x_gpio_set_uulp_npss_pin(LED_PIN);  // Alternative

    DEBUGOUT("LED ON\n");
  }
  else
  {
    // OFF - Use the correct API
    sl_si91x_gpio_set_uulp_npss_pin_value(LED_PIN, 0);  // Try this
    // OR
    // sl_si91x_gpio_clear_uulp_npss_pin(LED_PIN);  // Alternative

    DEBUGOUT("LED OFF\n");
  }
}
