<html>
<body>
<form action="Signup" method="POST">
	<div class="inp">
		<label for="uid">Enter UserID: </label>
		<input type="number" name="uid">
	</div>
	<div class="inp">
		<label for="pass">Enter Password: </label>
		<input type="text" name="pass">
	</div>
	<div class="inp">
		<label for="name">Enter Full Name: </label>
		<input type="text" name="name">
	</div>
	<div class="inp">
		<label for="dob">Enter Date of Birth: </label>
		<input type="date" name="dob">
	</div>		
<input type="submit">
</form>
<%
    String loginStatus = (String)request.getAttribute("loginStatus");
    if(loginStatus != null) {
        out.println("<p>" + loginStatus + "</p>");
    }
%>
<a href="login.jsp">Already Signed Up? Login Here </a>
</body>
</html>

