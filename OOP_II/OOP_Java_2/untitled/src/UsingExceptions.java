public class UsingExceptions {
	public static void main( String args[] ) {
		try {
			method1();
		}
		catch ( Exception exception ) {
			System.err.printf( "%s\n\n", exception.getMessage() );
			exception.printStackTrace(); // print exception stack trace
			StackTraceElement[] traceElements = exception.getStackTrace();
			System.out.println( "\nStack trace from getStackTrace:" );
			System.out.println( "Class\t\tFile\t\t\tLine\tMethod" );
			// loop through traceElements to get exception description
			for ( StackTraceElement element : traceElements ) {
				System.out.printf( "%s\t", element.getClassName() );
				System.out.printf( "%s\t", element.getFileName() );
				System.out.printf( "%s\t", element.getLineNumber() );
				System.out.printf( "%s\n", element.getMethodName() );
			}
		}
	}

	// call method2; throw exceptions back to main
	public static void method1() throws Exception
	{
		method2();
	}
	public static void method2() throws Exception {
		method3();
	}
	public static void method3() throws Exception
	{
		throw new Exception( "Exception thrown in method3" );
	}
}


