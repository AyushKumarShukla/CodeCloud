

import java.io.IOException;
import java.sql.Connection;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/Auth")
public class Auth extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public boolean authenticate()
	{
		final String JDBC_URL = "jdbc:mysql://localhost:3306/test";
	    final String JDBC_USER = "root";
	    final String JDBC_PASSWORD = "";
		Connection conn = DbConnect.connect(JDBC_URL,JDBC_USER,JDBC_PASSWORD);
		if(conn != null)
			System.out.print("Authenticated From Auth Class Successfully\n");
		else
			System.out.print("DUH");
			
		return false;
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		authenticate();
	}

}
