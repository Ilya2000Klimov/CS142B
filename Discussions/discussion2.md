letter = "a" | ... "z"| "A" | ... "Z" |
digit = "0" | ... "9" |

identifier = letter {letter | digit} |
number = digit {digit} |

computations=   "computation"
                {"var" ...
                ...

# Layout
## IO
## Tokenizer
## Parser
## Intermediary Representation
## Byte Code
# Identifiers
    number
    * / + -
    ()
    <- ; .
    computation
    var

# Finite State Machine
FileReader
    public char GetNext();          -> char GetNext()
    FileReader(string path);
    void error(string message);


Tokenizer
    public Token GetNext();         -> Token GetNext()
    Tokenizer(FileReader reader);
    void error(string message);


