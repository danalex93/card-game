#include <stdio.h>
#include <stdlib.h>
#include "codification.h"
#include "movements.h"

void send_to_player_two(size_t);
void receive_from_player_two(size_t);

int main(int argc, char const *argv[])
{
  struct movement my_move, their_move;
  size_t message

  my_move.user_id = 1;
  my_move.type = withdraw;
  my_move.card = 10;

  message = encode(my_move);
  send_to_player_two(message);

  receive_from_player_two(message);
  their_move = decode(message);

  printf("From Player Two: \n");
  printf("UserID: %d\n", their_move.user_id);
  printf("Type: %d\n", their_move.type);
  printf("Card: %d\n", their_move.card);

  return 0;
}