// DecryptData.cpp
//
// THis file uses the input data and key information to decrypt the input data
//

#include "Main.h"

// YOU WILL DELETE ALL THIS CODE WHEN YOU DO YOUR PROJECT - THIS IS GIVING YOU EXAMPLES OF HOW TO 
// ACCESS gPasswordHash AND gKey

void decryptData_01(char *data, int sized)
{
	int hop0;
	int curRound = gNumRounds;
	
	__asm
	{
BIG_LOOP:

        lea esi, gPasswordHash

        mov edi, data

        xor ecx, ecx// zero out the count register for the loop, and used for data
        xor eax, eax// using eax for the key

		mov ebx, curRound

		//Index
        mov ah, byte ptr[esi + ebx * 4]
        mov al, byte ptr[esi + 1 + ebx *4]

		//Hop Count:
		xor edx, edx
		mov dh, byte ptr[2 + ebx + esi * 4]
		mov dl, byte ptr[3 + ebx + esi *4]
		cmp edx, 0
		jne HERE
		mov edx, 0xFFFF
		//mov edi, data just in ca

	HERE:
			mov hop0, edx
			xor edx, edx
			//edx is free
			xor ebx, ebx
			mov edi, data
			xor ecx, ecx

    LOOP_START:         

			//EAX is Starting Index, ECX is Hop Count
			add eax, hop0 // [ebp-4]
			cmp eax, 65537
			jl DO_NOTHING
			sub eax, 65537d

	DO_NOTHING :
          
			//B :
			   xor ebx, ebx

			   // data is in dl
			   clc
			  
			   mov bh, dl
			   and bh, 0x0f //--bh = bcda 0000
			   shr bh, 4 // 0000 bcda
			   mov dh, bh // dh = 0000 bcda
			   shr dh, 1 // dh = 0000 0bcd
			   and bh, 0x01 // bh = 0000 000a
			   shl bh, 3 // 0000 a000
			   add bh, dh // == 0000 abcd
			   shl bh, 4 // abcd 0000

			   xor dh, dh

			   mov bl, dl//	0000 hefg
			   mov dh, dl //tmp 
			   shl bl, 5 // efg0 0000
			   and dh, 0x80 // h000 0000
			   shr dh, 3 //000h 0000
			   add bl, dh //efgh 0000 
			   and bl, 0xF0
			   shr bl, 4 // 0000 efghg

			   // dl and dh hold the two nibbles
			   add bh, bl // bcda0000 + 0000hefg = bcda hefg

			   //DATA IS NOW IN B
			xor edx, edx

			//A:
			mov dl, byte ptr[gDecodeTable + ebx]
			
			//DATA IS IN D
			// 
			//C :
			mov esi, 8
			RVSLoop :
				shr dl, 1
				Rcl  bh, 1
				dec esi
				jnz RVSLoop
				xor edx, edx
				mov dl, bh
			//DATA IN D

			//D:
			xor dl, 0x95

			//E :
			rol dl, 2


		   //PUT DATA BACK
		   mov byte ptr[ecx + edi], dl
           //Increment the count register
           inc ecx

           cmp ecx, sized
           jl LOOP_START// to determine when to end the for loop

		mov bl, byte ptr[gkey + eax] // gets 1 byte of key set			//<-- this must be done AFTER BACDE
		mov dl, byte ptr[ecx + edi]   // gets 1 byte of data set
		xor dl, bl //perform the xor on the two data sets
					//put data back from dl
		mov byte ptr[ecx + edi], dl  ///
    
	xor ebx, ebx
	dec curRound
	mov ebx, curRound
	cmp ebx, 0
	jg BIG_LOOP

				
	}

	return;
} // decryptData_01


//////////////////////////////////////////////////////////////////////////////////////////////////
// EXAMPLE code to show how to access global variables
int decryptData(char *data, int dataLength)
{
	int resulti = 0;

	gdebug1 = 0;					// a couple of global variables that could be used for debugging
	gdebug2 = 0;					// also can have a breakpoint in C code

	// You can not declare any local variables in C, but can use resulti to indicate any errors
	// Set up the stack frame and assign variables in assembly if you need to do so
	// access the parameters BEFORE setting up your own stack frame
	// Also, you cannot use a lot of global variables - work with registers

	/*__asm {
		// you will need to reference some of these global variables
		// (gptrPasswordHash or gPasswordHash), (gptrKey or gkey), gNumRounds

		// simple example that xors 2nd byte of data with 14th byte in the key file
		lea esi,gkey				// put the ADDRESS of gkey into esi
		mov esi,gptrKey;			// put the ADDRESS of gkey into esi (since *gptrKey = gkey)

		lea	esi,gPasswordHash		// put ADDRESS of gPasswordHash into esi
		mov esi,gptrPasswordHash	// put ADDRESS of gPasswordHash into esi (since unsigned char *gptrPasswordHash = gPasswordHash)

		mov al,byte ptr [esi+0]				// get first byte of password hash
		mov al,byte ptr [esi+1]				// get 5th byte of password hash
		mov ebx,2
		mov al,byte ptr [esi+ebx]			// get 3rd byte of password hash
		mov al,byte ptr [esi+ebx*2]			// get 5th byte of password hash

		mov ax,word ptr [esi+ebx*2]			// gets 5th and 6th bytes of password hash ( gPasswordHash[4] and gPasswordHash[5] ) into ax
		mov eax,dword ptr [esi+ebx*2]		// gets 4 bytes, as in:  unsigned int X = *( (unsigned int*) &gPasswordHash[4] );

		mov al,byte ptr [gkey+ebx]			// get's 3rd byte of gkey[] data

		mov al,byte ptr [gptrKey+ebx]		// THIS IS INCORRECT - will add the address of the gptrKey global variable (NOT the value that gptrKey holds)

		mov al,byte ptr [esi+0xd];			// access 14th byte in gkey[]: 0, 1, 2 ... d is the 14th byte
		mov edi,data						// Put ADDRESS of first data element into edi
		xor byte ptr [edi+1],al				// Exclusive-or the 2nd byte of data with the 14th element of the keyfile
											// NOTE: Keyfile[14] = 0x21, that value changes the case of a letter and flips the LSB
											// Lowercase "c" = 0x63 becomes capital "B" since 0x63 xor 0x21 = 0x42
	}
	*/
	return resulti;

}  //decryptData

