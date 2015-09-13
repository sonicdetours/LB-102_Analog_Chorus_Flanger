build/nm102/time.o: avrlib/time.cc avrlib/time.h avrlib/base.h \
 avrlib/timer.h avrlib/avrlib.h avrlib/size_to_type.h
build/nm102/adc.o: avrlib/adc.cc avrlib/adc.h avrlib/avrlib.h \
 avrlib/base.h avrlib/size_to_type.h
build/nm102/random.o: avrlib/random.cc avrlib/random.h avrlib/base.h
build/nm102/serial.o: avrlib/serial.cc avrlib/serial.h avrlib/avrlib.h \
 avrlib/base.h avrlib/size_to_type.h avrlib/gpio.h avrlib/timer.h \
 avrlib/ring_buffer.h
build/nm102/string.o: avrlib/string.cc avrlib/string.h avrlib/base.h
build/nm102/wii_nunchuk.o: avrlib/devices/wii_nunchuk.cc \
 avrlib/devices/wii_nunchuk.h avrlib/i2c/i2c.h avrlib/gpio.h \
 avrlib/avrlib.h avrlib/base.h avrlib/size_to_type.h avrlib/timer.h \
 avrlib/ring_buffer.h
build/nm102/nm102.o: nm102/nm102.cc avrlib/gpio.h avrlib/avrlib.h \
 avrlib/base.h avrlib/size_to_type.h avrlib/timer.h avrlib/boot.h \
 avrlib/adc.h avrlib/time.h nm102/lfo.h nm102/timer.h nm102/patch.h
