#include <stdio.h>
#include <string.h>
#include "solve_cube.h"
    
//checks if there is any valid edge piece at the Up layer
boolean isAnyUpEdgePieceValid(){
    int j=0;
    
    char* upColor = getUpMidColor();
    char* frontColor = getFrontColor(0,j,1);
    char* frontUpColor = getUpColor(0,j,1);
    char* leftColor = getLeftColor(1,j,0);
    char* leftUpColor = getUpColor(1,j,0);
    char* backColor = getBackColor(2,j,1);
    char* backUpColor = getUpColor(2,j,1);
    char* rightColor = getRightColor(1,j,2);
    char* rightUpColor = getUpColor(1,j,2);
    
    boolean isFrontPieceValid = !((strcmp(frontColor,(upColor))==0)?true:false) && !((strcmp(frontUpColor,(upColor))==0)?true:false);
    boolean isLeftPieceValid = !((strcmp(leftColor,(upColor))==0)?true:false) && !((strcmp(leftUpColor,(upColor))==0)?true:false);
    boolean isBackPieceValid = !((strcmp(backColor,(upColor))==0)?true:false) && !((strcmp(backUpColor,(upColor))==0)?true:false);
    boolean isRightPieceValid = !((strcmp(rightColor,(upColor))==0)?true:false) && !((strcmp(rightUpColor,(upColor))==0)?true:false);
    
    if(isFrontPieceValid || isLeftPieceValid || isBackPieceValid || isRightPieceValid)
        return true;
    else 
        return false;
}

//checks if the edge piece at 001 is valid 
boolean isUpEdgePieceValid(){
    char* upColor = getUpMidColor();
    char* frontColor = getFrontColor(0,0,1);
    char* frontUpColor = getUpColor(0,0,1);
    
    boolean isFrontPieceValid = !((strcmp(frontColor,(upColor))==0)?true:false) && !((strcmp(frontUpColor,(upColor))==0)?true:false);
    
    if(isFrontPieceValid)
        return true;
    else 
        return false;
}

//checks if any edge piece in the middle layer is invalid/(incorrectly placed)
boolean isAnyMiddleEdgePieceInvalid(){
    int j=1;
    
    char* frontColor = getFrontMidColor();
    char* leftColor = getLeftMidColor();
    char* backColor = getBackMidColor();
    char* rightColor = getRightMidColor();
    
    char* frontFMLColor = getFrontColor(0, j, 0);
    char* leftFMLColor = getLeftColor(0, j, 0);
    char* leftBMLColor = getLeftColor(2, j, 0);
    char* backBMLColor = getBackColor(2, j, 0);
    char* backBMRColor = getBackColor(2, j, 2);
    char* rightBMRColor = getRightColor(2, j, 2);
    char* rightFMRColor = getRightColor(0, j, 2);
    char* frontFMRColor = getFrontColor(0, j, 2);
    
    boolean isFMLValid = ((strcmp(frontFMLColor,(frontColor))==0)?true:false) && ((strcmp(leftFMLColor,(leftColor))==0)?true:false);
    boolean isBMLValid = ((strcmp(leftBMLColor,(leftColor))==0)?true:false) && ((strcmp(backBMLColor,(backColor))==0)?true:false);
    boolean isBMRValid = ((strcmp(backBMRColor,(backColor))==0)?true:false) && ((strcmp(rightBMRColor,(rightColor))==0)?true:false);
    boolean isFMRValid = ((strcmp(rightFMRColor,(rightColor))==0)?true:false) && ((strcmp(frontFMRColor,(frontColor))==0)?true:false);
    
    if(!isFMLValid || !isBMLValid || !isBMRValid || !isFMRValid){
        return true;
    }
    else{
        return false;
    }
}