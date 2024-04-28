package com.ayush;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/DbConnect")
public class DbConnect extends HttpServlet {
	private static final long serialVersionUID = 1L;

	static public Connection connect()
	{
		final String JDBC_URL = "jdbc:mysql://localhost:3306/test";
	    final String JDBC_USER = "root";
	    final String JDBC_PASSWORD = "";
	    try 
	    {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD);
            System.out.print("Conn Created");
            return conn;
	    }
	    catch(ClassNotFoundException e)
	    {
	    	System.out.print("CLASSNOTFOUND");
	    	return null;
	    } catch (SQLException e) 
	    {
			System.out.print("SQL TROUBLE");
			return null;
		}
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		PrintWriter out = response.getWriter();
		Connection conn = connect();
		if(conn != null)
			out.print("<h2>SUCCESS</h2>");
		else
			out.print("failed");
		request.setAttribute("conn",conn);
		RequestDispatcher rq = request.getRequestDispatcher("Auth");
		rq.forward(request,response);
			
	}
}
