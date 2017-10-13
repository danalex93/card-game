typedef enum movement_types { 
  withdraw, // => 0
  play,     // => 1
  turn,     // => 2
  discard   // => 3
} movement_types;

struct movement{
   int user_id;          // =>  8 bits for user_id
   movement_types type;   // => 2 bits for movement_type
   int card;              // => 8 bits for card identificator
};