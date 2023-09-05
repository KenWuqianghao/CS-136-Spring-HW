/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// 
//
// Name: Ken Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include "sequence.h"
#include "cs136-trace.h"

// The maximum number of values that can be stored in a sequence.
static const int SEQUENCE_MAX_LENGTH = 100;

struct sequence seq_init(void) {
	struct sequence s = {0, {0}};
    return s;
}

// See sequence.h for documentation.
int sequence_length(const struct sequence *seq){
	return seq->length;
}

// See sequence.h for documentation.
char sequence_item_at(const struct sequence *seq, int pos){
	return seq->data[pos];
}

// See sequence.h for documentation.
bool sequence_insert_at(struct sequence *seq, int pos, char value){
	if (seq->length == SEQUENCE_MAX_LENGTH) {
		return false;
	}

	for (int i = seq->length; i > pos; --i) {
		seq->data[i] = seq->data[i - 1];
	}

	seq->data[pos] = value;
	seq->length++;
	return true;
}

// See sequence.h for documentation.
char sequence_remove_at(struct sequence *seq, int pos){
	char removed = seq->data[pos];
	for (int i = pos; i < seq->length - 1; ++i) {
		seq->data[i] = seq->data[i + 1];
	}
	seq->length--;
	return removed;
}

// See sequence.h for documentation.
void sequence_print(const struct sequence *seq){
	assert(seq);
	if (seq->length == 0) {
		printf("[empty]\n");
	} else {
		printf("[%d]:", seq->length);
		for (const char *p = seq->data; p < seq->data + seq->length; ++p) {
			printf("%c", *p);
		}
		printf("\n");
	}
}
