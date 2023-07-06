#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <time.h>

int const CODE_LENGTH = 4;
int attempts = 10;

void _usage(void) {
  printf("Usage:\n");
  printf(" -c <code>\n");
  printf(" -t <attempts>\n");
  exit(8);
}

void _random_code_gen(char *code) {
  time_t t;

  /* Intializes random number generator */
  srand((unsigned)time(&t));
  int used_digit[10] = {0};
  char const digit[] = "012345678";
  int generated_code_length = 0;
  while (generated_code_length < CODE_LENGTH) {
    int random_int = rand() % 9;
    // PS: This is sooooo inefficient, but we'll take it
    if (used_digit[random_int] == 1) {
      continue;
    }
    code[generated_code_length] = digit[random_int];
    used_digit[random_int] = 1;
    generated_code_length++;
  }
}

int _codecmp(char *code1, char *code2, int length) {
  int status = 0;
  for (int i = 0; i < length; i++) {
    if (code1[i] != code2[i]) {
      status = 1;
      break;
    }
  }
  return status;
}

int _validate_input(int inputted_code_length, char inputted_code[CODE_LENGTH]) {
  if (atoi(inputted_code) == 0) {
    printf("Wrong input!\nCode can only contain digits\n");
    return 1;
  }
  if (inputted_code_length > CODE_LENGTH) {
    printf("Wrong input!\nCode can only be four digits\n");
    return 1;
  }
  return 0;
}


int _get_input_code(char inputted_code[CODE_LENGTH]) {
  char uncleaned_inputted_code[CODE_LENGTH];
  char ch;
  int i = 0;
  while (read(0, &ch, 1)) {
    uncleaned_inputted_code[i] = ch;
    if (ch == '\n')
      break;
    i++;
  }
  if (ch == '\0') // handle ctrl+D
    exit(0);

  int error_status = _validate_input(i, uncleaned_inputted_code);
  if (error_status != 0)
    return 1;

  for (int j=0; uncleaned_inputted_code[j] != '\n'; j++)  {
    inputted_code[j] = uncleaned_inputted_code[j];
  }
  return 0;
}

void _check_inputted_code(int *well_placed_pieces, int *misplaced_pieces, char *code, char inputted_code[CODE_LENGTH]) {
  *well_placed_pieces = 0;
  *misplaced_pieces = 0;
  for (int i = 0; i < CODE_LENGTH; i++) {
    if (code[i] == inputted_code[i]) {
      *well_placed_pieces = *well_placed_pieces + 1;
      continue;
    }
    for (int j = 0; j < CODE_LENGTH; j++) {
      if (code[i] == inputted_code[j] && i != j) {
        *misplaced_pieces = *misplaced_pieces + 1;
        break;
      }
    }
  }
}

void _mastermind(char *code, int attempts, int total_attempts) {
  if (attempts == total_attempts)
    return;
  printf("---\nRound %i\n", attempts);
  char inputted_code[CODE_LENGTH];
  int result;
  int input_error_status = _get_input_code(inputted_code);
  if (input_error_status != 0) {
    return _mastermind(code, attempts + 1, total_attempts);
  }

  int _well_placed_pieces, misplaced_pieces;
  result = _codecmp(code, inputted_code, CODE_LENGTH);
  if (result == 0) {
    printf("Congratz! You did it!\n");
    return;
  } else {
    _check_inputted_code(&_well_placed_pieces, &misplaced_pieces, code, inputted_code);
    printf("Well placed pieces: %i\nMisplaced pieces: %i\n", _well_placed_pieces, misplaced_pieces);
    return _mastermind(code, attempts + 1, total_attempts);
  }
}

int main(int argc, char *argv[]) {
  char code[] = "0000";
  int code_is_set = 0;

  while (argc > 1) {
    if (argv[0][0] == '-') {
      switch (argv[0][1]) {
      case 't':
        attempts = atoi(argv[1]);
        break;

      case 'c':
        for (int j = 0; j < CODE_LENGTH; j++) {
          code[j] = argv[1][j];
        }
        code_is_set = 1;
        break;

      default:
        printf("Wrong Argument: %s\n", argv[1]);
        _usage();
      }
    }
    argv++;
    argc--;
  }

  if (code_is_set != 1) {
    _random_code_gen(code);
  }

  printf("Will you find the secret code?\nPlease enter a valid guess\n");
  _mastermind(code, 0, attempts);
}