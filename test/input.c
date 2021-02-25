int main() {
  int x; int y;
  int *iptr;
  x= 10; y= 20;
  iptr= &x + 4;
  printint( *iptr);

  return(0);
}
