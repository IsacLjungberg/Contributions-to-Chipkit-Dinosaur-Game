void setPixel (int x, int y, int color){ //sets a pixel based on x y coordinate in the icon 2d array
    int space = (int) floor(x / 32); //determines which of 4 areas
    int row = (int) floor(y / 8); //determines row
    int column = (int) floor((x % 32) / 8); //determines column
    int byteNum = (x % 32) % 8; //determines which byte within the row and column
    int bitNum = y % 8; //determines which bit within the byte
    if(x >= 0 && x <= 128 && y >= 0 && y <= 32){//doesn't write if pixel is outside of screen
      if(color){//sets black pixel
          (icon[space][row*32 + column*8+byteNum]) |= (0x1<<bitNum);
      }else{//sets white pixel
          (icon[space][row*32 + column*8+byteNum]) &= ~(0x1<<bitNum);
      }
    }
}

drawPseudoBitmap(int x0, int y0, int x[], int y[], int length){//reads specific pseudo bitmaps and draws on display
	int n;
	for(n = 0; n < length; n++){
		setPixel(x0 + x[n], y0 + y[n], 0);
	}
}

void collision(){//result of collision
  int lettersGO[] = {6,0,12,4,14,21,4,17};
  drawCharacterLine(32, 1, lettersGO, 8);
  gameOver = 1;
}

void collisionCheck(int n){//math for checking collision of dinosaur with specified obstacle
  int typeSizeX;
  int typeSizeY;
  switch (obsType[n]) //sets obstacle size based on type
  {
  case 1:
    typeSizeX = 3;
    typeSizeY = 8; 
    break;
  case 2:
    typeSizeX = 3;
    typeSizeY = 8; 
    break;
  case 3:
    typeSizeX = 8;
    typeSizeY = 6; 
    break;
  case 4:
    typeSizeX = 8;
    typeSizeY = 8; 
    break;
  case 5:
    typeSizeX = 13;
    typeSizeY = 8; 
    break;
  default:
    break;
  }
  /* collisions maths */
  if((dinoX <= (obsX[n]) && (obsX[n]) <= (dinoX + dinoSizeX)) || (dinoX <= (obsX[n] + typeSizeX) && (obsX[n] + typeSizeX) <= (dinoX + dinoSizeX))){
    if((dinoY <= (obsY[n]) && (obsY[n]) <= (dinoY + dinoSizeY)) || (dinoY <= (obsY[n] + typeSizeY) && (obsY[n] + typeSizeY) <= (dinoY + dinoSizeY))){
      collision();
    }
  }
}

void collisionCheckAll(){//check all obstacles for collision, with all corners
  int n;
  for(n = 0; n < 8; n++){
      collisionCheck(n); //check dino collision with specified obst
  }
}
