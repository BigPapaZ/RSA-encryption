Name: Zaigham A. Randhawa

Project no. 1 RSA

Files submitted: 

1. ReallyLongInt.cpp/hpp: A basic implementation for making numbers greater than unsigned long long.

2. numberTheory.tpp/hpp: A set of functions to make our RSA calculations easier.

3. keygen.cpp: Generates a public and a private key file. 

4. encrypt.cpp: Uses a public key to encrypt the plain file.

5. decrypt.cpp: Uses a private key to decrypt the encrypted file. 

6. ReallyLongInt_TEST.cpp: Tests the functionality of the ReallyLongInts. 

7. numberTheory_TEST.cpp: Tests the functionality of the numberTheory file functions. 

8. catch.hpp: Provides a framework for the test files to run and catch errors.

9. Makefile: Shortens our time spent on the terminal by give us ready made command. 

10. readme.txt: A guide to running this project.
 
How to run RSA:

    Basic:

        Put a .txt file named "plain.txt" into a folder with  the above files. Open the command line terminal 
        and type: make runRSA. A file named "encry.txt" will appear in the folder with the encrypted text, 
        and a file named "decry.txt" will appear with the decrypted text.


    key generation:

        Write 'make encry' (without the commas) on the command line terminal. Then write './ a b public.txt private.txt' 
        on the command line. "a" and "b" represent 2 prime numbers whose product is at least 256. You will get 2 files 
        "public.txt" with the public encryption key and "private.txt" with the private decryption key. 

    encryption:

        You will need a file, let us say 'public.txt', with the public encryption key and a plain text file, 
        let us call it 'plain.txt'. On the command line, write 'make encry'. Let us say you want the encrypted text in the 
        file 'encry.txt'. Then after compilation, write './encry public.txt plain.txt encry.txt'. You will get the encrypted 
        text in the 'encry.txt'. You dont need to create 'encry.txt', the program will automatically create it. 

    decryption:

        You will need a file, let us say 'private.txt', with the private decryption key and an encrypted text file, 
        let us call it 'encry.txt'. On the command line, write 'make decry'. Let us say you want the decrypted text in 
        the file 'decry.txt'. Then after compilation, write './decry private.txt encry.txt decry.txt'. You will get the 
        decrypted text in the 'decry.txt'. You dont need to create 'decry.txt', the program will automatically create it. 


How to run tests:

    Write 'make runtests' (without the commas) on the command line terminal. The tests will run automatically. 
    
Bugs:

This code is made of stalinium...never breaks.


