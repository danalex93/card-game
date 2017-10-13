#include <stdio.h>
#include <stdlib.h>
#include "movements.h"

#define CARD_SIZE     32
#define TYPE_SIZE     2
#define USER_ID_SIZE  8

#define CARD_BITS    4294967295  // => 2^32 - 1  => 32 active bits
#define TYPE_BITS    3           // => 2^2 - 1   => 3  active bits
#define NAME_BITS    255         // => 2^8 - 1   => 8  active bits

size_t encode(struct movement m)
{
  size_t code;
  size_t helper;

  // Add Card to Code
  code = m.card;

  // Move Card and Add Type
  helper = m.type;
  code = code | (helper << CARD_SIZE);

  // Move Card & Type and Add user_id
  helper = m.user_id;
  code = code | (helper << (CARD_SIZE+TYPE_SIZE));

  return code;
}

struct movement decode(size_t code)
{
  struct movement m;
  size_t helper;

  // Set Helper to CARD_BITS and Obtain Usign AND
  helper = CARD_BITS;
  m.card = code & helper;

  // Set Helper to TYPE_BITS and Obtain Usign AND
  helper = TYPE_BITS;
  m.type = (code & (helper << CARD_SIZE)) >> CARD_SIZE;

  // Set Helper to NAME_BITS and Obtain usign AND
  helper = NAME_BITS;
  m.user_id = (code & (helper << (CARD_SIZE+TYPE_SIZE))) >> (CARD_SIZE+TYPE_SIZE);

  return m;
}