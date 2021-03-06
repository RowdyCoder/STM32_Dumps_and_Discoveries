
//LD3 RED Connected to PC6
//LD4 ORG Connected to PC8
//LD5 GRN Connected to PC9
//LD6 BLU Connected to PC7

#define PERIPH_BASE 		0x40000000UL
#define AHB1_OFFSET			0x00020000UL
#define AHB2_OFFSET 		0x08000000UL
#define AHB1_PERIPH_BASE    PERIPH_BASE + AHB1_OFFSET
#define AHB2_PERIPH_BASE 	PERIPH_BASE + AHB2_OFFSET
#define GPIOC_OFFSET		0x00000800UL
#define GPIOC_BASE			AHB2_PERIPH_BASE + GPIOC_OFFSET
#define RCC_OFFSET			0x00001000UL
#define RCC_BASE			AHB1_PERIPH_BASE + RCC_OFFSET
#define AHBEN_R_OFFSET		0x14UL

//type cast to a register and dereferenced
#define RCC_AHBEN_R			(*(volatile unsigned int *) (RCC_BASE + AHBEN_R_OFFSET))
#define MODER_OFFSET		0x0000UL
//type cast to a register and dereferenced
#define GPIOC_MODE_R		(*(volatile unsigned int *) (GPIOC_BASE + MODER_OFFSET))

#define ODR_OFFSET		    0x14UL
#define GPIOC_OD_R			(*(volatile unsigned int *) (GPIOC_BASE + ODR_OFFSET))

#define GPIOC_CLK_EN		(1U<<19) //set bit 19 to 1

#define USER_LED3_MODER		(1U<<12)
#define USER_LED4_MODER		(1U<<16)
#define USER_LED5_MODER		(1U<<18)
#define USER_LED6_MODER		(1U<<14)

#define USER_LED3 			(1U<<6) //red
#define USER_LED4 			(1U<<8) //orange
#define USER_LED5 			(1U<<9) //green
#define USER_LED6 			(1U<<7) //blue

typedef struct
{

}RCC_TypeDef;

typedef struct
{

}GPIO_Type;

int main(void)
{
	/*enable clock access to port C*/

	RCC_AHBEN_R	 |= GPIOC_CLK_EN;

	/*configure led pins as output pins*/

	GPIOC_MODE_R |= USER_LED3_MODER |USER_LED4_MODER | USER_LED5_MODER | USER_LED6_MODER;

	while(1)
	{
		/*Turn on all LEDS*/
		//GPIOC_OD_R |= USER_LED3 | USER_LED4| USER_LED5 | USER_LED6;

		/*Toggle LED3*/
		GPIOC_OD_R ^= USER_LED3 | USER_LED6 | USER_LED4;
		for (int i = 0; i < 1000000; i++)
		{

		}
	}
}




















