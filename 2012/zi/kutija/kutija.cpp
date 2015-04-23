#include <cstdio>

int main() {
  int num_steps;
  int sum_right = 0;
  int move_right = 0;
  int sol = 0;
  
  scanf("%d", &num_steps);
  for (int i = 0; i < num_steps; ++i) {
    int curr_down, curr_right;
    scanf("%d%d", &curr_down, &curr_right);

    if (!move_right) {
      move_right = curr_down;
    }
    
    sum_right += curr_right;
    
    if (move_right <= sum_right) {
      ++sol;
      move_right = 0;
      sum_right = 0;
    }
  }

  if (!move_right) {
    printf("dobar\n%d\n", sol);
  } else {
    printf("ponor\n%d\n", sol+1);
  }
  

  return 0;
}
