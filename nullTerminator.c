char decryptedtext[]="blabla text123";  // declare char string and fill it with "blabla text123"

int decryptedtext_len=strlen(decryptedtext);  // declare int with the string length of decryptedtext

decryptedtext[decryptedtext_len] = '\0'; // set at the end of string an null terminator ...(this is the end of string)
