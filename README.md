# cpp 00 - ex00
### megaphone

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

* Quando usare std::endl e quando '\n'
std::endl = a capo + flush: utile quando devi vedere il testo subito (per esempio un prompt prima di leggere da tastiera).
'\n' = solo a capo: più veloce in generale, perché non forza il flush ogni volta.

### Che cos’è std?
→ std è il nome dello namespace (una “scatola di nomi”) dove vivono quasi tutte le cose della libreria standard: cout, string, toupper, endl, ecc.
In C++ i nomi vengono organizzati in namespace per evitare scontri di nomi tra la tua roba e la libreria.

### Che cos’è ::?
→ :: è l’operatore di risoluzione di ambito: significa “vai dentro quella scatola e prendi questo nome”.

* Quindi:
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

```

```