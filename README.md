# Biblioteka ShiftRegister74HC595

ShiftRegister74HC595 je Arduino biblioteka koja omogućava upravljanje sa više 74HC595 shift registara istovremeno. Ova biblioteka olakšava proširivanje izlaznih i ulaznih pinova Arduino mikrokontrolera koristeći samo nekoliko pinova mikrokontrolera.

### Instalacija

1. Preuzmite najnoviju verziju biblioteke sa [GitHub repozitorijuma](https://github.com/rasho/74HC595).
2. Otvorite Arduino IDE.
3. Kliknite na **Sketch** u meniju Arduino IDE, zatim na **Include Library** i na **Add .ZIP Library**.
4. Pronađite preuzetu biblioteku i odaberite je.
5. Biblioteka će biti instalirana i spremna za upotrebu.

### Uključivanje biblioteke

Da biste koristili ShiftRegister74HC595 biblioteku, dodajte sledeću liniju koda na početak vašeg Arduino projekta:

```cpp
#include <ShiftRegisterMulti.h>
```

### Kreiranje objekta

Pre nego što počnete koristiti funkcionalnosti biblioteke, trebate kreirati objekat klase ShiftRegisterMulti. To možete uraditi na sledeći način:

```cpp
// Kreiranje objekta biblioteke
ShiftRegisterMulti shiftRegisters(dataPin, latchPin, clockPin, numRegisters, numPinsPerRegister);
```

Gde su:

- `dataPin`, `latchPin` i `clockPin`: Brojevi pinova koje koristite za komunikaciju sa shift registrima.
- `numRegisters`: Broj shift registara koje koristite.
- `numPinsPerRegister`: Broj pinova po svakom shift registru.

### Metode

ShiftRegisterMulti biblioteka sadrži sledeće metode:

- `begin()`: Inicijalizacija biblioteke. Pozovite ovu metodu u funkciji `setup()` pre početka korišćenja shift registara.
- `setOutput(registerIndex, pinIndex, state)`: Postavlja izlazno stanje određenog pina na određenom registru.
- `setAllOutputs(state)`: Postavlja izlazno stanje svih pinova na svim registrima na istu vrednost.
- `setAllOutputsLow()`: Postavlja izlazno stanje svih pinova na svim registrima na LOW (isključeno) stanje.
- `setAllOutputsHigh()`: Postavlja izlazno stanje svih pinova na svim registrima na HIGH (uključeno) stanje.
- `setClockFrequency(frequency)`: Postavlja frekvenciju takta za shift registre.
- `getInputState(registerIndex, pinIndex)`: Vraća trenutno stanje ulaznog pina na određenom registru.
- `updateRegisters()`: Ažurira stanje registara i prenosi podatke na izlazne pinove.
- `setPinMode(registerIndex, pinIndex, pinMode)`: Postavlja režim rada određenog pina na određenom regist

ru.
- `getPinMode(registerIndex, pinIndex)`: Vraća trenutno podešen režim rada određenog pina na određenom registru.
- `setOutputHoldTime(holdTime)`: Postavlja vreme zadržavanja izlaznog stanja pre nego što se registri ažuriraju.
- `getOutputHoldTime()`: Vraća trenutno podešeno vreme zadržavanja izlaznog stanja.
- `readInputStates(inputStates)`: Očitava stanje svih ulaznih pinova i smešta ih u niz `inputStates`.

### Licence

Ova biblioteka je dostupna pod [MIT licencom](https://github.com/example/shift-register-multi/blob/main/LICENSE).

### Autor

Biblioteku ShiftRegisterMulti je razvio [Radenko Bogdanovic](https://github.com/rasho). Ako imate bilo kakva pitanja, možete se obratiti autoru.

### Problemi i doprinosi

Ako primetite bilo kakve probleme prilikom korišćenja biblioteke ili imate predloge za poboljšanje, slobodno otvorite novi problem (issue) na [GitHub stranici projekta](https://github.com/rasho/74HC595/issues). Takođe, pozivamo vas da doprinesete razvoju biblioteke kroz otvaranje novih zahteva za povlačenje (pull request).

### Zaključak

ShiftRegisterMulti biblioteka pruža jednostavan način za upravljanje sa više 74HC595 shift registara na Arduino platformi. Sa ovom bibliotekom, možete proširiti izlazne i ulazne pinove vašeg Arduino projekta na jednostavan način.
