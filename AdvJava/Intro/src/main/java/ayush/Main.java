package ayush;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Main extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    public Main() {
        super();
    }

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			
			int num1 = Integer.parseInt(request.getParameter("num1"));
			int num2 = Integer.parseInt(request.getParameter("num2"));
			
			int res = num1+num2;
			
			response.setContentType("text/html"); 
          
			PrintWriter out = response.getWriter(); 
	          
			out.print("<html><body>"); 
			out.print("<h2>SUM:</h2>");
			out.format("%d + %d = %d",num1,num2,res);
			out.print("</body></html>");
	}

}
