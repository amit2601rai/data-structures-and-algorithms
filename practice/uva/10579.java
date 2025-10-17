package uva.prob_10579;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	private static BigInteger [][] matrixMult(BigInteger [][] a,BigInteger [][] b){
		BigInteger [][] c = new BigInteger[2][ 2];
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					if(c[i][k] != null)
						c[i][k] = c[i][k].add(a[i][j].multiply(b[j][k]));
					else
						c[i][k] = a[i][j].multiply(b[j][k]);
				}
			}
		}
		return c;
	}
	
	
	private static BigInteger [][] matrixMult2(BigInteger [][] a,BigInteger [][] b){
		BigInteger [][] c = new BigInteger[2][ 1];
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<1;k++){
					if(c[i][k] != null)
						c[i][k] = c[i][k].add(a[i][j].multiply(b[j][k]));
					else
						c[i][k] = a[i][j].multiply(b[j][k]);
				}
			}
		}
		return c;
	}
	
	private static BigInteger [][] matrixPow(BigInteger [][] matrix,int n){
		if(n == 1)
			return matrix;
		if(n%2 == 0)
			return matrixMult(matrixPow(matrix,n/2),matrixPow(matrix,n/2));
		else 
			return matrixMult(matrix,matrixMult(matrixPow(matrix,(n-1)/2),matrixPow(matrix,(n-1)/2)));
	}
	
	public static void main(String [] args){
		int n;
		Scanner sc = new Scanner(System.in);
	    while(sc.hasNextInt()){
	    	n = sc.nextInt();
	    	if(n == 1 || n == 2){
				System.out.println("1");
				continue;
			}
	    	BigInteger [][] matrix = new BigInteger [2][2];
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					if(i == 0)matrix[i][j] = new BigInteger("1");
					else if(j == 0) matrix[i][j] = new BigInteger("1");
					else matrix[i][j] = new BigInteger("0");
				}
			}
			BigInteger [][] matrix2 = new BigInteger [2][1];
			matrix2[0][0] = new BigInteger("1");
			matrix2[1][0] = new BigInteger("1");
			matrix = matrixPow(matrix,n-2);
			matrix = matrixMult2(matrix, matrix2);
			System.out.println(matrix[0][0].toString());
	    }
	}
}