int max_by_level(int level) {
  switch (level) {
  case 1:
    return 10;
  case 2:
    return 50;
  case 3:
    return 100;
  default:
    return 0;
  }
}
