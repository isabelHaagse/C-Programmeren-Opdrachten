
/*
	Doel van de opdracht: Leren omgaan met linked lists.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>


struct LinkedlistInt {
	int getal;
	struct LinkedlistInt* volgendElement;
};


struct LinkedlistInt* nieuw_element(int nieuwGetal) {
	struct LinkedlistInt* nieuwElement = malloc(sizeof(struct LinkedlistInt));

	if (nieuwElement == NULL) {
		return NULL;
	}

	nieuwElement->getal = nieuwGetal;
	nieuwElement->volgendElement = NULL;

	return nieuwElement;
}


struct LinkedlistInt* maak_linkedlist_int(int* arrayInt, int lengteArrayInt) {
	struct LinkedlistInt* head = NULL;

	printf("%d\n", arrayInt[2]);

	for (int element = 0; element < lengteArrayInt; element++) {
		struct LinkedlistInt* nieuwElement = nieuw_element(arrayInt[element]);
		nieuwElement->volgendElement = head;
		head = nieuwElement;
	}

	return head;
}


void print_linkedlist_int(struct LinkedlistInt* head) {
	if (head == NULL) {
		return;
	}

	int element = 1;

	printf("Head\n");

	while (head->volgendElement != NULL) {
		struct LinkedlistInt* ditElement = head;
		head = head->volgendElement;
		printf("Element: %d \t Getal: %d\n", element, ditElement->getal);
		element++;
	}

	printf("Element: %d \t Getal: %d\n", element, head->getal);

	printf("Staart\n");
}


struct LinkedlistInt* verwijder_element(struct LinkedlistInt* head, int verwijderElement) {
	if (head == NULL) {
		return NULL;
	}
	
	struct LinkedlistInt* vorigElement = head;
	struct LinkedlistInt* vorigHead = head;

	if (verwijderElement == 1) {
		return head->volgendElement;
	}
	else if (verwijderElement <= 0) {
		return head;
	}

	head = head->volgendElement;

	for (int element = 1; element < verwijderElement-1; element++) {
		if (head->volgendElement == NULL) {
			return head;
		}
		
		vorigElement = head;
		head = head->volgendElement;
	}

	vorigElement->volgendElement = head->volgendElement;
	free(head);

	return vorigHead;
}


struct LinkedlistInt* verwijder_negatieve_getallen(struct LinkedlistInt* head) {
	if (head == NULL) {
		return NULL;
	}
	else if (head->volgendElement == NULL && head->getal < 0) {
		return NULL;
	}

	struct LinkedlistInt* vorigeHead = head;
	int element = 1;
	
	 do{
		struct LinkedlistInt* ditElement = head;
		head = head->volgendElement;

		if (ditElement->getal < 0) {
			vorigeHead = verwijder_element(vorigeHead, element);
		}
		else {
			element++;
		}
	 } while (head->volgendElement != NULL);

	 if (head->getal < 0) {
		 vorigeHead = verwijder_element(vorigeHead, element);
	 }

	return vorigeHead;
}


struct LinkedlistInt* toevoegen_element(struct LinkedlistInt* head, int toevoegElement, int nieuwGetal) {
	if (head == NULL || toevoegElement < 1) {
		return head;
	}

	struct LinkedlistInt* vorigeHead = head;
	struct LinkedlistInt* vorigElement = head;	
	
	if (toevoegElement <= 0) {
		return head;
	}

	struct LinkedlistInt* nieuwElement = nieuw_element(nieuwGetal);

	if (toevoegElement == 1) {
		nieuwElement->volgendElement = vorigeHead;
		return nieuwElement;
	}
	
	head = head->volgendElement;

	int element = 1;
	for (element; element < toevoegElement - 1; element++) {
		if (head->volgendElement == NULL) {
			vorigElement = head;
			head = head->volgendElement;
			break;
		}

		vorigElement = head;
		head = head->volgendElement;		
	}

	nieuwElement->volgendElement = vorigElement->volgendElement;
	vorigElement->volgendElement = nieuwElement;

	return vorigeHead;
}


struct LinkedlistInt* toevoegen_element_eind(struct LinkedlistInt* head, int nieuwGetal) {
	if (head == NULL) {
		return head;
	}

	struct LinkedlistInt* vorigeHead = head;
	struct LinkedlistInt* vorigElement = head;

	struct LinkedlistInt* nieuwElement = nieuw_element(nieuwGetal);


	while (head->volgendElement != NULL) {
		head = head->volgendElement;
	}

	head->volgendElement = nieuwElement;

	return vorigeHead;
}

struct LinkedlistInt* verwijder_element_begin(struct LinkedlistInt* head) {
	return verwijder_element(head, 1);
}


void verwijder_linkedlist(struct LinkedlistInt* head) {
	struct LinkedlistInt* volgendElement = NULL;
	do {
		volgendElement = head->volgendElement;
		free(head);
		head = volgendElement;
	} while (head != NULL);
}




/*
	Functie: linkedlists_main()
	Beschrijving:
		Deze functie bevat de code om de opdracht te voltooien, het kan via de runfile worden aangeroepen.
		
*/

int linkedlists_main() {
	// array
	int integerLijst[10] = { 0 };
	int lengteLijst = sizeof(integerLijst) / sizeof(integerLijst[0]);

	for (int element = 0; element < lengteLijst; element++) {
		integerLijst[element] = element;
	}

	integerLijst[0] = -9;
	integerLijst[4] = -1;
	integerLijst[9] = -10;

	// Opdracht a
	struct LinkedlistInt* linkedlistIntHead = maak_linkedlist_int(integerLijst, lengteLijst);

	print_linkedlist_int(linkedlistIntHead);


	// Opdracht b
	linkedlistIntHead = verwijder_element(linkedlistIntHead, 4);

	print_linkedlist_int(linkedlistIntHead);


	// Opdracht c & d
	linkedlistIntHead = verwijder_negatieve_getallen(linkedlistIntHead);

	print_linkedlist_int(linkedlistIntHead);


	// Opdracht e
	linkedlistIntHead = toevoegen_element(linkedlistIntHead, 1, 100);

	print_linkedlist_int(linkedlistIntHead);

	// Opdracht f
	linkedlistIntHead = toevoegen_element_eind(linkedlistIntHead, 200);
	print_linkedlist_int(linkedlistIntHead);

	// Opdracht g
	linkedlistIntHead = verwijder_element_begin(linkedlistIntHead);
	print_linkedlist_int(linkedlistIntHead);

	// Opdracht h
	linkedlistIntHead = toevoegen_element_eind(linkedlistIntHead, 300);
	linkedlistIntHead = verwijder_element_begin(linkedlistIntHead);
	linkedlistIntHead = toevoegen_element_eind(linkedlistIntHead, 400);
	linkedlistIntHead = verwijder_element_begin(linkedlistIntHead);

	print_linkedlist_int(linkedlistIntHead);


	verwijder_linkedlist(linkedlistIntHead);


	return 0;
}