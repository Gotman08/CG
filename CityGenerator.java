package CG;

import java.lang.Math;
import java.util.Random;

public class CityGenerator{
    
    private int Street = 0;
    private int Home = 1;
    private int[][] City;
    //City -> Home, street, tree, 

    public CityGenerator(int n){
        this.City = new int[n][n];
    }

    public void remplire(){
        for(int i = 0; i < City.length; i++){
            for(int j = 0; j < City[i].length; j++){
                this.City[i][j] = (new Random()).nextInt(2);
            }
        }
    }

    private int[][] GenerateCity(){
        for(int i = 0; i < City.length; i++){
            for(int j = 0; j < City[i].length; j++){
                verification(City, i, j);
            }
        }
    }

    private boolean verification(int[][] t,int i , int j){
        if(i != 0 && j != 0 || i != 0 && j != (t[i].length - 1) || i == (t.length - 1) && j == 0 || i == (t.length - 1) && j == (t[i].length - 1)){
            
            switch (i) {
                case 0:
                    res = (t[i][j] == t[i+1][j] && t[i][j] == t[i+1][j-1] && t[i][j] == t[i][j-1] && t[i][j] == t[i][j+1] && t[i][j] == t[i+1][j+1]);
                    break;
                case 1:
                    res = (t[i][j] == t[i+1][j] && t[i][j] == t[i+1][j-1] && t[i][j] == t[i][j-1] && t[i][j] == t[i][j+1] && t[i][j] == t[i+1][j+1] && t[i][j] == t[i-1][j] && t[i][j] == t[i-1][j-1] && t[i][j] == t[i-1][j+1]);
                    break;
                case 2:
                default:
                    break;
            }
        }
    }

    public int[][] getCity(){
        return this.City;
    }
}