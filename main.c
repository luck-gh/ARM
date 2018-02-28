#include <led.h>
#include <adc.h>
#include <key.h>
#include <uart.h>
#include <lcd.h>
#include <font.h>
#include <mmu.h>
#include <vector.h>
#include <wdt.h>
#include <timer.h>
#include <rtc.h>
#include <tp.h>

void do_data_abt(void)
{
	printf("occur a data abort exception...\n");
}

void do_unde(void)
{
	printf("occur a undefined exception...\n");
}

void do_svc(u32 imm)
{
	printf("svc call %d\n", imm);
}

void do_wdt(void)
{
	printf("wdt timer...\n");
	iowrite32(9527, WTCLRINT);
}

void gh_memcpy(u32 old, u32 new, u32 gh_size_t)
{
	int i=0;
	if(new < 0x20){
		new = (int *)FRAMBUFF0 + 800*480*new;
		old = (int *)FRAMBUFF0 + 800*480*old;
	}
	while(gh_size_t--){
		i++;
		*(((int *)new)+i) = *(((int *)old)+i);
	}
}

int main(void)
{
	int val;
	int i,j = 0;

	/*创建异常矢量表*/
	cp_vector_table((void *)TTB_BASE, VECTOR_BASE);

	lcd_init();

	gh_clr_screen(1,0xFF03F5);
	gh_clr_screen(2,0xFF03F5);
//	gh_clr_screen(2,0xF00305);

	//printf("1 ** %#x\n",ioread32(VIDW00ADD0B0));
	//gh_memcpy(1,2,800*480);
	gh_printf(1,i    ,200,"hello world  1",0xFFFB03,0xFF03F5);
	gh_change_buf(1);
	for(i = 0; i < 800; i++) {
		if(!j){
			j = 1;
			gh_printf(2,i-1	  ,200,"hello world  ",0xFF03F5,0xFF03F5);
			gh_printf(2,i+1   ,200,"hello world  ",0xFFFB03,0xFF03F5);
			gh_change_buf(2);
		}else{
			j = 0;
			gh_printf(1,i-1	  ,200,"hello world  ",0xFF03F5,0xFF03F5);
			gh_printf(1,i+1   ,200,"hello world  ",0xFFFB03,0xFF03F5);
			gh_change_buf(1);
		}
		udelay(5000000);
	}
/*
	adc_init();

	while (1) {
		udelay(500000);
		val = get_adc_val_irq(0); 
		if (val < 0) {
			printf("error adc...\n");
			break;
		}
		printf("digital(%04d) --> %04dmv\n", 
				val, val*1800/4095);
	}
*/
	return 0;
}
