# bare-metal-series-stm32


## Video 3: PWM

Important Register: OCC --> Output compare register
ARR  --> Auto reload register

explanation about PWM --> freq depends on the ARR and prescaler

// freq = system_freq / ((prescaler-1) + (ARR-1))


I have written to function, one for setup the TIMER and enable the timer, configure the pwm stuff

second: function, that can set the duty_cycle