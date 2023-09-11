package lab;

public class VectorTest {
    		public class VectorTest 
		{
		   private static final String colors[] = { "red", "white", "blue" };
	
		   public VectorTest()
		   {	      Vector< String > vector = new Vector< String >();
		      printVector( vector ); // print vector
		
		      // add elements to the vector
		      for ( String color : colors )
		         vector.add( color ); 
		
	      printVector( vector ); // print vector
		      
                   }
}
