timer0.rel: timer0.c timer0.h
	sdcc -c timer0.c

LCD1602.rel: LCD1602.c LCD1602.h
	sdcc -c LCD1602.c

delayxms.rel: delayxms.c delayxms.h
	sdcc -c delayxms.c

clock: timer0.rel LCD1602.rel
	sdcc clock.c timer0.rel LCD1602.rel
	sudo stcgal clock.ihx

loopseg: timer0.rel delayxms.rel
	sdcc loopseg.c timer0.rel delayxms.rel
	sudo stcgal loopseg.ihx

star: timer0.rel
	sdcc star.c timer0.rel
	sudo stcgal star.ihx

matrix: delayxms.rel
	sdcc matrix.c delayxms.rel
	sudo stcgal matrix.ihx

clean:
	rm *.rel *.lst *.asm *.map *.mem *.lk *.ihx *.sym *.rst
