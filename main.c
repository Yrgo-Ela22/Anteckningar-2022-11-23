/********************************************************************************
* main.c: Demonstration av datastruktur f�r implementering av AD-omvandling
*         f�r analoga signaler. I detta fall l�ses analog pin A0 / PORTC0
*         f�r PWM-styrning av tre lysdioder med en periodtid p� 10 000 us.
********************************************************************************/
#include "led.h"
#include "button.h"
#include "led_vector.h"
#include "adc.h"

/********************************************************************************
* main: Ansluter tre lysdioder till pin 8 - 10, en tryckknapp till pin 13 samt
*       en potentiometer till analog pin A0. Lysdioderna lagras i en dynamisk
*       vektor f�r kollektiv PWM-styrning. Vid nedtryckning av tryckknappen
*       sker avl�sning av den analoga insignalen fr�n potentiometern och anv�nds
*       f�r att kontrollera ljusstyrkan p� lysdiodenrna, �vrig tid h�lls de
*       sl�ckta. En PWM-period p� 10 000 us anv�nds.
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

