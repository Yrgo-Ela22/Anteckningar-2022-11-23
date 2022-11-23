/********************************************************************************
* main.c: Demonstration av datastruktur för implementering av AD-omvandling
*         för analoga signaler. I detta fall läses analog pin A0 / PORTC0
*         för PWM-styrning av tre lysdioder med en periodtid på 10 000 us.
********************************************************************************/
#include "led.h"
#include "button.h"
#include "led_vector.h"
#include "adc.h"

/********************************************************************************
* main: Ansluter tre lysdioder till pin 8 - 10, en tryckknapp till pin 13 samt
*       en potentiometer till analog pin A0. Lysdioderna lagras i en dynamisk
*       vektor för kollektiv PWM-styrning. Vid nedtryckning av tryckknappen
*       sker avläsning av den analoga insignalen från potentiometern och används
*       för att kontrollera ljusstyrkan på lysdiodenrna, övrig tid hålls de
*       släckta. En PWM-period på 10 000 us används.
********************************************************************************/
int main(void)
{
   struct led l1, l2, l3;
   struct button b1;
   struct adc a1;
   struct led_vector v1;

   led_init(&l1, 8);
   led_init(&l2, 9);
   led_init(&l3, 10);

   button_init(&b1, 13);
   adc_init(&a1, A0);
   led_vector_init(&v1);

   led_vector_push(&v1, &l1);
   led_vector_push(&v1, &l2);
   led_vector_push(&v1, &l3);
   
   while (1)
   {
      if (button_is_pressed(&b1))
      {
         adc_get_pwm_values(&a1, 0);

         led_vector_on(&v1);
         delay_us(a1.pwm_on_us);

         led_vector_off(&v1);
         delay_us(a1.pwm_off_us);
      }
   }

   return 0;
}

