package com.ayush;


import java.io.IOException;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/Auth")
public class Auth extends HttpServlet {
	private static final long serialVersionUID = 1L;

	public static boolean authenticate(int uid, String pass) throws SQLException
	{

		Connection conn = DbConnect.connect();
		String fetch = String.format("SELECT * FROM LOGIN_DETAILS WHERE uid = %d AND password = '%s'",uid,pass);
		Statement stmt = conn.createStatement();
		if(conn != null)
		{
			System.out.print("Conn received by auth\n");
			ResultSet rs = stmt.executeQuery(fetch);
			ResultSetMetaData meta = rs.getMetaData();
			int colcnt = meta.getColumnCount();
			System.out.print("AUTH: COLUMN COUNT " + colcnt);
			if(rs.next())
			{
				return true;
			}
		}
		return false;
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		int uid =  (int) request.getAttribute("uid");
		String pass = (String) request.getAttribute("pass");
		try {
			authenticate(uid,pass);
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}

}
