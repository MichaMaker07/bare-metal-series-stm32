#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/vector.h>

#define LED_PORT	(GPIOA)
#define LED			(GPIO5)

#define CPU_FREQ	(84000000)
#define SYSTICK_FEQ	(1000)

volatile uint64_t ticks = 0;   // volatile wird oft bei Registern und Interrupt Variablen benutzt
void sys_tick_handler(void) {
	ticks++;
}

static uint64_t get_ticks(void) {
	return ticks;
}
static void rcc_setup(void) {
	rcc_clock_setup_pll(&rcc_hsi_configs[RCC_CLOCK_3V3_84MHZ]);
}

static void gpio_setup(void) {
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED);
}



static void systick_setup(void) {
	systick_set_frequency(SYSTICK_FEQ, CPU_FREQ);
	systick_counter_enable();
	systick_interrupt_enable();
}
int main(void) {
	rcc_setup();
	gpio_setup();
	systick_setup();
	uint64_t start_time = get_ticks();
	while(1) {
		if (get_ticks() - start_time >= 1000) {
			gpio_toggle(LED_PORT, LED);
			start_time = get_ticks();
		}
	}
	// Never return
	return 0;
}

