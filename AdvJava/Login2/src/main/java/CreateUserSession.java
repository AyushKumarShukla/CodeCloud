

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import com.ayush.Auth;

@WebServlet("/CreateUserSession")
public class CreateUserSession extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		int uid = Integer.parseInt(request.getParameter("uid"));
		String pass = request.getParameter("pass");
		RequestDispatcher dis = null;
		try {
			if(!Auth.authenticate(uid, pass))
			{
				request.setAttribute("loginStatus", "LOGIN FAILED<br>USER NOT AUTHENTICATED");
				dis = request.getRequestDispatcher("login.jsp");
				dis.forward(request, response);
			}
			else
			{
				HttpSession session = request.getSession();
				session.setAttribute("uid", uid);
				session.setAttribute("pass", pass);
				session.setAttribute("loginStatus", true);
	
				request.getRequestDispatcher("welcome.jsp").forward(request, response);
			}
				
		} catch (SQLException e) {
			System.out.println("ERROR LOGIN:SQL TROUBLE");
			e.printStackTrace();
		}
		
	}

}
