#include <targets\AT91SAM7.h>

void time_delay(int ms){
volatile int aa,bb;
for(aa=0;aa<=ms;aa++){
for(bb=0;bb<=3000;bb++){
__asm__("NOP");
}
}
}

//Sterownik (driver) traktowany jest jako zestaw funkcji przeznaczonych do obsługi danego urządzenia peryferyjnego.
//Sterowniki powinny realizować następujące funkcje:


void PIO_clock_enable(int pio_pcer, int a_b){ //pio_pcer 1 dla enable, 0 dla diable; a_b: 0 - PIOA, 1 - PIOB
if(pio_pcer==1){
PMC_PCER|=pio_pcer<<a_b+2;}
if(pio_pcer==0){
PMC_PCDR|=1<<a_b+2;}
}


void PIO_enable(int line_no, int ena)
{
if(ena){
PIOB_PER = 1<<line_no;
}else
{
PIOB_PDR = 1<<line_no;
}
} //załączanie kontroli nad wybranym PINem dla PIO Controllera (np. PIN 65 kontroluje PB20), dwa parametry: nr linii i stan 0/1 gdzie PER lub PDR //1 załącza kontrolę PIO dla danej linii; 0 wyłącza kontrolę PIO dla danej linii

void PIO_output_enable(int line_no, int ena)
{
if(ena)
{
PIOB_OER = 1<<line_no;
}else
{
PIOB_ODR = 1<<line_no;
}
} //wybór czy dana linia ma być output czy input - dwa parametry, nr linii i stan: 0-input, 1-output OER lub ODR

void PIO_output_state(int line_no, int ena)
{
if(ena)
{
PIOB_CODR = 1<<line_no;
}else{
PIOB_SODR = 1<<line_no;
}
} // ustawienie stanu wybranej linii, dwa parametry, nr linii i stan: 0-cleared, 1-set SODR lub CODR lub ODSR (jeśli używasz ODSR pamiętaj o OWER)

void PIO_output_negate(int line_no)
{
//PIO_OWER = 1 <<line_no;
// PIO_ODSR^= 1<<line_no;
} //neguje stan linii output, pamiętać o konfiguracji w OWER - negacja może być przeprowadzona negacja wyłącznie poprzez ODSR (jeśli używasz ODSR pamiętaj o OWER)

//Funkcje odczytu przycisków
unsigned int SW_odczyt(unsigned int SW_numer)
{
if(SW_numer==1)
{
return PIOB_PDSR & (1<<24);
}else if (SW_numer == 2){
return PIOB_PDSR & (1<<25);
}
} // czytaj stan przycisku SW1 lub SW2

unsigned int SW_czytaj(void)
{

} // funkcja czeka dopóki przycisk jest naciśnięty

int main()
{
PIO_clock_enable(1,1);
PIO_enable(20,1);



PIO_enable(24,1);
PIO_enable(25,1);
PIO_output_enable(20,1);

/* while(1)
{
SW_czytaj();
if(SW_odczyt(1)==0)
{
PIO_output_state(20,0);
}else if (SW_odczyt(2)==0)
{
PIO_output_state(20,1);
}



}
*/
bool zmienna=false;
while(1)
{
SW_czytaj();
if(SW_odczyt(1)==0)
{ if(zmienna==false)
{
PIO_output_state(20,0);
zmienna=true;
}else
{
PIO_output_state(20,1);
zmienna=false;
}


}
//time_delay(100);


}




}