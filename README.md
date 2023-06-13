# Biblioteka ShiftRegister74HC595

Ova biblioteka omogućava jednostavno upravljanje sa 74HC595 siftregistrom na Arduino platformi. Omogućava vam da lako podešavate izlazne pinove na registru i izvodite različite efekte kao što su blinkanje, postepeno pojačavanje/smanjivanje svetlosti, pulsiranje, slučajno blinkanje, talasni efekat i još mnogo toga.

## Instalacija

1. Preuzmite biblioteku kao ZIP datoteku.
2. Otvorite Arduino IDE.
3. Izaberite opciju "Sketch" u meniju, zatim "Include Library" i na kraju "Add .ZIP Library".
4. Izaberite prethodno preuzetu ZIP datoteku biblioteke.
5. Biblioteka je sada uspešno instalirana i spremna za upotrebu.

## Korišćenje

1. Uključite biblioteku u svom Arduino kodu koristeći `#include <ShiftRegister74HC595.h>`.
2. Kreirajte instancu klase `ShiftRegister74HC595` sa odgovarajućim pinovima za povezivanje sa registrom, na primer: `ShiftRegister74HC595 shiftRegister(DATA_PIN, LATCH_PIN, CLOCK_PIN, NUM_REGISTERS)`, gde su `DATA_PIN`, `LATCH_PIN` i `CLOCK_PIN` brojevi pinova koje koristite, a `NUM_REGISTERS` broj registara koje koristite.
3. Pomoću metoda klase `ShiftRegister74HC595` postavite željene izlazne vrednosti i izvodite efekte na registrima.

## Metode

### Konstruktor

- `ShiftRegister74HC595(int data, int latch, int clock, int num)` - Kreira instancu klase ShiftRegister74HC595. Parametri su brojevi pinova za povezivanje sa registrom (`data`, `latch`, `clock`) i broj registara (`num`).

### Postavljanje izlaza

- `void setOutput(int pin, bool value)` - Postavlja izlazni pin na određenu vrednost (HIGH ili LOW) na svim registrima.
- `void setOutput(int registerIndex, int pin, bool value)` - Postavlja izlazni pin na određenu vrednost (HIGH ili LOW) na određenom registru.

### Ažuriranje registara

- `void updateRegisters()` - Ažurira registre i osvežava izlazne vrednosti na registru.

### Poništavanje registara

- `void clearRegisters()` - Postavlja sve izlazne vrednosti na registru na LOW (0).

### Pomeranje

- `void shiftLeft()` - Pomeranje sadržaja registara ulevo.
- `void shiftRight()` - Pomeranje sadržaja registara udesno.

### Efekti

- `void blinkEffect(int registerIndex, int pin, int interval)` - Blinkanje određenog pina na registru sa zadatim intervalom.
- `void fadeEffect(int registerIndex, int pin, int duration)` - Post

epeno pojačavanje i smanjivanje svetlosti određenog pina na registru sa zadatom dužinom trajanja.
- `void pulseEffect(int registerIndex, int pin, int duration)` - Pulsiranje određenog pina na registru sa zadatom dužinom trajanja.
- `void randomBlinkEffect(int registerIndex, int pin, int interval)` - Slučajno blinkanje određenog pina na registru sa zadatim intervalom.
- `void waveEffect(int duration, int interval)` - Talasni efekat preko svih pinova na registrima sa zadatom dužinom trajanja i intervalom.
- `void fadingTrailEffect(int duration, int interval)` - Efekat postepenog gašenja svetlosti preko svih pinova na registrima sa zadatom dužinom trajanja i intervalom.
- `void sparkleEffect(int numPins, int duration, int interval)` - Efekat treperenja nasumično odabranog broja pinova na registru sa zadatom dužinom trajanja i intervalom.
- `void runningLightsEffect(int direction, int speed)` - Efekat trčećih svetala u određenom smeru i sa zadatom brzinom.

## Napomena

Ova biblioteka je razvijena za upotrebu na Arduino platformi i testirana je na kompatibilnim mikrokontrolerima. Može biti prilagođena ili proširena prema vašim potrebama.

## Autor

Biblioteka ShiftRegister74HC595 je razvijena od strane Radenka Bogdanovica. Ako imate pitanja, sugestije ili problema, slobodno me kontaktirajte na [rasho984@gmail.com].
