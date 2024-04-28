
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import com.ayush.Auth;
import com.ayush.DbConnect;
@WebServlet("/Signup")
public class Signup extends HttpServlet {
	private static final long serialVersionUID = 1L;
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		PrintWriter out = response.getWriter();
		int uid =  Integer.parseInt(request.getParameter("uid"));
		String pass = request.getParameter("pass");
		String name = request.getParameter("name");
		String dob = request.getParameter("dob");
		RequestDispatcher rd = request.getRequestDispatcher("index.jsp");
		
		try {
			if(!Auth.authenticate(uid,pass))
			{
				System.out.println("User Does Not Exist: Needs to Be Inserted into DB");
				Connection conn = DbConnect.connect();
				Statement stmt = conn.createStatement();
				String ins_login = String.format("INSERT INTO LOGIN_DETAILS VALUES (%d,'%s')",uid,pass);
				String ins_user = String.format("INSERT INTO USER_DETAILS VALUES(%d,'%s','%s')",uid,name,dob);
				int status_ins_login = stmt.executeUpdate(ins_login);
				// if login details are inserted
				if(status_ins_login != 0)
				{
					System.out.println("Login Data Inserted Successfully");
					int status_ins_user = stmt.executeUpdate(ins_user);
					//if user details are inserted
					if(status_ins_user != 0)
					{
						System.out.println("User Data Inserted Successfully");
						// redirect to the front page
						request.setAttribute("loginStatus", "Sign Up Successfull");
						rd.forward(request, response);
					}
					else
						System.out.println("User Data Insertion Failed");
				}
			}
			else
			{
				request.setAttribute("loginStatus", "Credentials Already Exist<br>Please Retry With Different Credentials....");
				rd.forward(request, response);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
	}

}
