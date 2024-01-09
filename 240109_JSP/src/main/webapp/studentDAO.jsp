<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.ArrayList"%>
<%@ page import="com.javalex.ex.studentDAO"%>
<%@ page import="java.sql.*"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>학생 목록</title>
</head>
<body>
    <h2>학생 목록</h2>
    <table border="1">
        <thead>
            <tr>
                <th>학번, 이름, 나이, 학년, 전공</th>
            </tr>
        </thead>
        <tbody>
            <%
                studentDAO dao = new studentDAO();
                ArrayList<String> studentList = dao.showAllStudent();
                for (int i=0; i<studentList.size(); i++) {
            %>
                <tr>
                    <td><%= studentList.get(i) %></td>
                </tr>
            <%
                }
            %>
        </tbody>
    </table>
</body>
</html>