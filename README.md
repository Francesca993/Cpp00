# **cpp 00**
# Exercise 00: Megaphone

→ Prendere input da riga di comando e trasformalo in maiuscolo.
→ Se non ci sono input stampa " * LOUD AND UNBEARABLE FEEDBACK NOISE * "

### Librerie:
<iostream> → flusso di output C++ (std::cout, std::cerr, std::endl). Nel subject è richiesto di risolvere “in modo C++”, e le funzioni *printf() sono vietate (pena 0) quindi userai gli stream C++ al posto di printf.
Ti dà std::cout (scrive messaggi normali) e std::cerr (scrive messaggi di errore).

<cctype> → funzioni sui caratteri come std::toupper per trasformare in maiuscolo.

<string> → se vuoi manipolare argomenti copiandoli in std::string (consentito usare la standard lib C++ “C++-ish”).

In C++:

```
std::cout << "ciao" << std::endl;
```

Usa gli stream C++ (std::cout, std::cerr).
std::endl o '\n'?
std::endl stampa un “a capo” e fa il flush (spinge subito il testo sullo schermo).
'\n' stampa solo “a capo” (di solito più veloce).

```
std::cout << "Ciao" << '\n';      // a capo
std::cerr << "Errore!" << std::endl; // a capo + flush (per errori va benissimo)
```

### Cos’è uno “stream”

- stream = flusso di dati che scorre da/a il tuo programma.
i più usati sono:
- std::cout → uscita per i messaggi normali (va sullo schermo).
- std::cerr → uscita per i messaggi di errore (di solito esce subito).
- std::cin → ingresso dalla tastiera.
per mandare cose dentro a un tubo d’uscita usi l’operatore <<
L’operatore << è come infilare cose nel tubo:
```
std::cout << "Numero: " << 42 << '\n';
```
### cos’è il buffer (e perché esiste)
scrivere sullo schermo carattere-per-carattere è “costoso”. quindi gli stream accumulano i caratteri in un buffer. quando in buffer è pieno, o quando ha senso, il contenuto viene inviato tutto insieme allo schermo: è più veloce.
→ std::cout di solito è bufferizzato: a volte scrivi, ma non vedi subito sullo schermo perché sta accumulando.
→ std::cerr in pratica si comporta come non bufferizzato: quello che scrivi compare subito (utile per errori e debug).
quando il programma finisce, i buffer vengono svuotati automaticamente.

### cos’è il flush

→ flush = “svuota adesso il buffer”. manda subito allo schermo (o al file) tutto ciò che era accumulato.

modi per fare flush:

- std::endl: va a capo e fa flush.
```
std::cout << "ciao" << std::endl; // newline + flush
```

- std::flush: fa solo flush (niente a capo).
```
std::cout << "inserisci il nome: " << std::flush;
```

**Quando usare std::endl e quando '\n'**
std::endl = a capo + flush: utile quando devi vedere il testo subito (per esempio un prompt prima di leggere da tastiera).
'\n' = solo a capo: più veloce in generale, perché non forza il flush ogni volta.

### Che cos’è std?
→ std è il nome dello namespace (una “scatola di nomi”) dove vivono quasi tutte le cose della libreria standard: cout, string, toupper, endl, ecc.
In C++ i nomi vengono organizzati in namespace per evitare scontri di nomi tra la tua roba e la libreria.

### Che cos’è ::?
→ :: è l’operatore di risoluzione di ambito: significa “vai dentro quella scatola e prendi questo nome”.

**Quindi:**
- std::cout = “la cout della scatola std”.
- std::string = “la string della scatola std”.
- std::toupper = “la toupper di std”.

Perché dobbiamo scriverlo “ogni volta”?
Per il subject è vietato fare using namespace std; (salvo esplicita eccezione). Se lo fai, prendi –42. Quindi devi qualificare sempre con std::.
Per chiarezza: vedere std::cout ti dice subito che è l’output standard C++, non una variabile tua chiamata cout.
Per evitare conflitti: se tu avessi una tua vector, o string, con std:: non c’è ambiguità.
Nota: non è una chiamata, non ha costo a runtime. È solo un’informazione in più per il compilatore.

E se mi scoccia scriverlo?
In C++ esiste using namespace std; per evitare di scrivere std:: ovunque, ma nel modulo 42 è vietato (–42). Potresti tecnicamente fare singole “using-declaration” tipo using std::cout; in ambito locale, ma per restare al 100% dentro lo spirito e le regole del subject, meglio non usarle e qualificare sempre con std::.

# Perché C++ è orientato agli oggetti

- OOP = organizzi il programma come oggetti (dati + funzioni insieme).
- C++ spinge l’OOP perché ti dà classi, costruttori, distruttori, public/private, operatori, ecc.

**OOP in 3 frasi**
→ Classe = stampo/ricetta.
→ Oggetto = istanza reale di quella ricetta.
→ Incapsulamento = i dettagli restano privati, esponi solo ciò che serve (pubblico).
In C tenevamo “struct + funzioni” separati. In C++ li mettiamo insieme dentro la classe: più ordine, meno errori.

- Classi + metodi: tieni vicini dati e azioni.
- public / private / const: controllo fine su cosa si può toccare.
- Costruttori/distruttori: stato valido alla nascita, pulizia alla fine.
- Operatori (es. operator<<) per API naturali.
- Namespace (std::): eviti collisioni di nomi.
- RAII: le risorse si gestiscono “agganciate alla vita” dell’oggetto.
codice più leggibile, meno bug, manutenzione facile.

### Le 4 idee chiave

**→ Incapsulamento – nascondi i dettagli:**

```
class Contact {
public:
  void setPhone(const std::string& p) { _phone = p; }
  std::string phone() const { return _phone; }
private:
  std::string _phone;
};
```

**→ Astrazione – usi l’oggetto senza sapere il “motore” sotto.**

**→ Costruzione/Distruzione – oggetti sempre in stato valido:**
```
class File {
public:
  File(const std::string& path);  // apre
  ~File();                         // chiude
};
```
**→ Ereditarietà/Polimorfismo – verranno dopo;**

# Schema mentale per scrivere una classe
**→ Nome e file:**
    - Contact.hpp, Contact.cpp.

**→ Header (.hpp) = interfaccia**
```
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();                          // opzionale: inizializza a vuoto
  void setName(const std::string& n);
  std::string name() const;

private:
  std::string _name;                  // dettagli nascosti
};

#endif
```

→ **Source (.cpp) = implementazione**
```
#include "Contact.hpp"

Contact::Contact() : _name() {}

void Contact::setName(const std::string& n) { _name = n; }
std::string Contact::name() const { return _name; }
```

# Come si dichiara una variabile in c++

```
int n;            // dichiarata ma NON inizializzata (valore spazzatura!)
int a = 0;        // inizializzata a 0 (copy-init)
int b(42);        // inizializzata a 42 (direct-init)

char c = 'X';
bool ok = true;

double pi = 3.14;
double z(0.0);

std::string s;               // stringa vuota (le classi si inizializzano da sole)
std::string t = "ciao";      // copia la stringa letterale
std::string u("hello");      // costruita con il costruttore

/*–––––– Riferimenti e Puntatori ––––––*/

const int ci = 10;      // in genere i const primitivi DEVONO essere inizializzati
const std::string cs;   // ok: costruttore di default → stringa vuota (const ma vuota)

int v = 7;
int& ref = v;           // riferimento: deve essere inizializzato subito e non può puntare ad altro
ref = 9;                // modifica v

int* p = &v;            // puntatore: può cambiare a chi “punta”
p = 0;                  // in C++98 usa 0 o NULL come “null pointer” (non c’è nullptr)

/* –––––– Array (statici) e inizializzazione ––––––––– */
int a[4];               // elementi NON inizializzati (garbage)
int b[4] = {0};         // tutti a 0
char msg[] = "ciao";    // 'c','i','a','o','\0'
```

# Come si scrive una funzione in c++

**Funzioni che prendono std::string**
→ Non devo modificare l’argomento → const std::string&
Evita copie e garantisci che non cambi.
```
#include <string>
#include <iostream>
#include <cctype>

void greet(const std::string& name) {
    std::cout << "Hello, " << name << '\n';
}
```

→ Devo modificare l’argomento → std::string&
Passi la stringa by reference e la funzione la può cambiare.
```
void toUpperInPlace(std::string& s) {
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        unsigned char uc = static_cast<unsigned char>(s[i]);
        s[i] = static_cast<char>(std::toupper(uc));
    }
}

```

→ Voglio restituire una stringa trasformata → ritorno per valore
Copierà il risultato (ok in cpp00).
```
std::string toUpperCopy(const std::string& s) {
    std::string out = s;
    toUpperInPlace(out);
    return out;
}
```
**Funzioni che prendono oggetti classe (es. Contact)**

```
// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
public:
    const std::string& first()  const;
    const std::string& last()   const;
    const std::string& nick()   const;
    const std::string& phone()  const;
    const std::string& secret() const;

    void setPhone(const std::string& p);
};

#endif
```

→ Sola lettura dell’oggetto → const Contact&
Niente copie, niente modifiche.
```
#include <iostream>

void printContact(const Contact& c) {
    std::cout << "First: "  << c.first()  << '\n'
              << "Last: "   << c.last()   << '\n'
              << "Nick: "   << c.nick()   << '\n'
              << "Phone: "  << c.phone()  << '\n'
              << "Secret: " << c.secret() << '\n';
}
```

→ Modificare l’oggetto → Contact&
```
void normalizePhone(Contact& c) {
    // esempio sciocco: se il numero è vuoto, metti "N/A"
    if (c.phone().empty()) {
        c.setPhone("N/A");
    }
}
```

→ Puntatore Contact* (alternativa al reference)
Utile quando l’oggetto può essere null o vuoi passare “nessun contatto”.
```
void setPhoneIfNotNull(Contact* c, const std::string& phone) {
    if (!c) return;
    c->setPhone(phone);
}

// uso:
Contact me;
setPhoneIfNotNull(&me, "12345"); // ok
setPhoneIfNotNull(0, "12345");   // non fa nulla

```
**Metodi dentro una classe (parametri stringa/oggetto)**

→ Metodi che prendono stringhe
```
class Contact {
public:
    void setFirst(const std::string& first);   // non copia l’argomento
    std::string fullName() const;              // restituisce per valore
private:
    std::string _first, _last;
};

// Contact.cpp
void Contact::setFirst(const std::string& first) { _first = first; }
std::string Contact::fullName() const { return _first + " " + _last; }
```

→ Metodi che prendono un altro oggetto (es. confronto)
```
class Contact {
public:
    bool sameNickAs(const Contact& other) const;
private:
    std::string _nick;
};

// Contact.cpp
bool Contact::sameNickAs(const Contact& other) const {
    return _nick == other._nick;
}
```
# Cos’è una classe (e perché esiste)

Una classe è un tipo che metti insieme tu, formato da:
* dati (campi, “variabili membro”)
* azioni (funzioni membro, dette anche metodi) che lavorano su quei dati

```
// Contact.hpp
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
private:                     // dati interni (nascosti)
    std::string firstName;
    std::string lastName;

public:                      // interfaccia (visibile a chi usa la classe)
    Contact();               // costruttore
    void setFirstName(const std::string& first);
    const std::string& getFirstName() const;  // non modifica l'oggetto
};

#endif
```
* private/public: con private proteggi i dati; con public esponi solo ciò che serve (incapsulamento).
* La classe definisce che cosa esiste; come funziona lo scriverai nel .cpp.

**→ “Dichiarare funzioni dentro la classe” = dichiarare metodi**
```
void setFirstName(const std::string& first);
const std::string& getFirstName() const;
```
non stai “mettendo funzioni dentro funzioni”: stai dichiarando i metodi della classe. Questi metodi:
* hanno accesso ai dati privati della classe
* ricevono in automatico un puntatore nascosto chiamato this (il “me stesso” dell’oggetto su cui stai lavorando)

**Dichiarazione** (firma) nel .hpp
**Definizione** (corpo) nel .cpp usando l’operatore di ambito :::
```
// Contact.cpp
#include "Contact.hpp"

Contact::Contact() : firstName(), lastName() {}  // costruttore

void Contact::setFirstName(const std::string& first) {
    this->firstName = first;  // 'this' punta all’oggetto corrente
}

const std::string& Contact::getFirstName() const {
    return firstName;
}
```
**Cos’è esattamente un metodo**
È una funzione “legata” a un tipo:
* Ha il prefisso di classe quando la definisci: Contact::setFirstName(...)
* Dentro il metodo puoi accedere ai membri senza prefisso (firstName) o con this->firstName
* Può essere marcato const alla fine: prometti che non modificherà i dati dell’oggetto
```
const std::string& getFirstName() const; // 'const' qui = non tocca i membri
```
# Operatori

**.   ->   ::   []   ()**
.: membro di un oggetto
->: membro tramite puntatore a oggetto
::: risoluzione di ambito (namespace/class) → std::cout, Contact::getFirstName
[]: indicizzazione/array
() : chiamata di funzione/operatore


# Exercise 01: My Awesome PhoneBook
**Programma stile “rubrica anni ’80” con 3 comandi: ADD, SEARCH, EXIT. All’avvio la rubrica è vuota.**

* Due classi:
    - PhoneBook → array di contatti, max 8. Se aggiungi il 9° → sovrascrivi il più vecchio (buffer circolare). Niente allocazione dinamica.
    - Contact → rappresenta un contatto. Campi: first name, last name, nickname, phone number, darkest secret (tutti non vuoti).
* SEARCH: mostra una tabella con 4 colonne (index, first name, last name, nickname), larghezza 10, allineate a destra, separate da |. Se il testo >10, tronca e l’ultimo carattere diventa un ‘.’. Poi chiedi l’indice da visualizzare (uno per riga).
Dopo ogni comando valido, il programma aspetta un altro comando; 
* EXIT chiude e “i contatti sono persi per sempre”. Qualsiasi altro input è ignorato. Dai un nome sensato all’eseguibile.

### Cos’è un costruttore (e quando viene chiamato)
È una funzione speciale della classe che viene eseguita automaticamente quando crei un oggetto.
Serve a mettere l’oggetto in uno stato valido fin dall’inizio (inizializzare i campi).

Esempi di chiamata “automatica”:
```
Contact c;               // chiama Contact::Contact()
Contact rubrica[8];      // chiama 8 volte Contact::Contact() (uno per ogni elemento)
```
### Cos’è un distruttore (e quando viene chiamato)
È la “funzione di addio” dell’oggetto: si esegue automaticamente quando l’oggetto muore (esce dallo scope, viene distrutto un array, finisce il main, ecc.).
Serve a rilasciare risorse che l’oggetto possiede: memoria presa con new, file aperti, socket, lock, ecc.
```
{
    Contact c;     // costruttore qui
}                  // fine blocco → ~Contact() qui

void f() {
    Contact tmp;
} // quando esci da f() → ~Contact()

int main() {
    Contact rubrica[8];
    // ...
} // alla fine del main → ~Contact() chiamato 8 volte (uno per elemento)
```
### Quando servono davvero costruttore e distruttore “personalizzati”
Servono quando devi fare lavori extra all’entrata/uscita dell’oggetto:
Aprire/chiudere un file
Allocare/Deallocare memoria con new/delete
Prendere/Rilasciare una risorsa (mutex, handle di sistema, ecc.)
Non servono (o possono restare vuoti) quando i membri sono tipi che si gestiscono da soli (come std::string).
Per ex01, tienili minimali:
Costruttore: ok vuoto (o con lista di init).
Distruttore: non dichiararlo proprio, oppure definiscilo vuoto se lo hai già dichiarato.
```

```

```

```