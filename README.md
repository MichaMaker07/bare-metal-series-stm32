# bare-metal-series-stm32


## Video 3: PWM

Important Register: OCC --> Output compare register
ARR  --> Auto reload register

explanation about PWM --> freq depends on the ARR and prescaler

// freq = system_freq / ((prescaler-1) + (ARR-1))


I have written to function, one for setup the TIMER and enable the timer, configure the pwm stuff

second: function, that can set the duty_cycle


## Video 4: Bootloader

We have split the app in bootloader and app

We are writting a simple bootloader -> Bootloader is a piece of software, which jumps to a specific address with the main app

- Prevent linking when the bootloader is larger than maximum allowed size -> change the linker script from 512kb to 32kb
- Pad the bootloader  to max size -> with a python script the free space will be filled up with 0xff