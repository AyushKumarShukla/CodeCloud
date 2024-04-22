

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;



public class Authenticate extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		PrintWriter out = response.getWriter();
	    final String JDBC_URL = "jdbc:mysql://localhost:3306/test";
	    final String JDBC_USER = "root";
	    final String JDBC_PASSWORD = "";
	    int uid = Integer.parseInt(request.getParameter("uid"));
	    String pass = request.getParameter("pass");
	    String loginStatus = "LOGIN FAILED";
	    
	  try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD);
            out.println("Database Connected");
            Statement stmt = conn.createStatement();
            
            String query = String.format("SELECT * FROM USER WHERE USERID=%d AND PASSWORD='%s'",uid,pass);
            ResultSet rd = stmt.executeQuery(query);
            if(rd.next())
            {
                loginStatus = "LOGIN SUCCESS";
                out.print(loginStatus);
            }
            else
            {
            	out.print("LOGIN CREDENTIALS DONT EXIST\nLOGIN FAILED");
            	loginStatus = "LOGIN FAILED";
            	request.setAttribute("loginStatus", loginStatus);
            	RequestDispatcher disp = request.getRequestDispatcher("index.jsp");
            	disp.forward(request, response);
            }
            conn.close();
            
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
            out.println("CLASS NOT FOUND");
        } catch (SQLException e) {
			out.print("SQL TROUBLE");
			e.printStackTrace();
		}
	}
}

