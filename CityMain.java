package CG;

import CG.CityGenerator;

public class CityMain{
    
    public static void afficher(int[][] t){
        
        for(int i = 0; i < t.length; i++){
            System.out.print("[ ");
            for(int j = 0; j < t[i].length; j++){
                if(j != t[i].length -1){
                    System.out.print(t[i][j] + ", ");
                }else{
                    System.out.print(t[i][j] + " ]");
                }
                
            }
            System.out.println("");
        }
       
    }
    
    public static void main(String[] args){
        CityGenerator CG = new CityGenerator(4);
        CG.remplire();
        afficher(CG.getCity());
    }
}