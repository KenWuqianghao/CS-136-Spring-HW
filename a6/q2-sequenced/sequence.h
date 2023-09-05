#include <stdbool.h>

#ifndef _SEQUENCE
#define _SEQUENCE
struct sequence {
    int length;
    char data[100];
};
#endif // _SEQUENCE

// seq_init() returns an initialized, i.e., empty, sequence.
struct sequence seq_init(void);

// sequence_length(seq) returns the length of sequence *seq.
int sequence_length(const struct sequence *seq);

// sequence_item_at(seq, pos) returns the item of sequence *seq at index pos.
// requires: pos must be between 0 (including) and sequence length (excluding)
char sequence_item_at(const struct sequence *seq, int pos);

// sequence_insert_at(seq, pos, item) inserts item into sequence *seq at
//   index pos. The function returns true if the item was inserted
//   successfully, or false if the sequence is at capacity.
// effects:  mutates *seq
// requires: pos must be between 0 and sequence length (both including)
bool sequence_insert_at(struct sequence *seq, int pos, char item);

// sequence_remove_at(seq, pos) removes the item of sequence *seq at index pos
//   and returns it.
// effects:  mutates *seq
// requires: pos must be between 0 (including) and sequence length (excluding)
char sequence_remove_at(struct sequence *seq, int pos);

// sequence_print(seq) prints the items of sequence *seq.
// effects: produces output
void sequence_print(const struct sequence *seq);