package com.javalex.ex.Controller;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.javalex.ex.Command.MemberService;
import com.javalex.ex.Command.MemberServiceDelete;
import com.javalex.ex.Command.MemberServiceInsert;
import com.javalex.ex.Command.MemberServiceLogin;
import com.javalex.ex.Command.MemberServiceSelect;
import com.javalex.ex.DTO.MemberDTO;

/**
 * Servlet implementation class CommandController
 */
@WebServlet("*.do")
public class CommandController extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CommandController() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doAction(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doAction(request, response);
	}

	protected void doAction(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		String uri=request.getRequestURI();
			// 사용자가 불러온 링크를 반환	(ex) /240117_JSP/insert.do
		String conPath=request.getContextPath();	// 프로젝트명 반환
		String command=uri.substring(conPath.length());
			// insert.do, delete.do ... 형식으로 저장
		
		// View(jsp), Controller(프론트컨트롤러, 커맨드)
		MemberService mService=null;		// 객체 생성X, 타입 구성만 한 것
		if(command.equals("/insert.do")) {	// "회원 추가" 수행을 요청할 시
			System.out.println("<회원 추가>를 수행합니다.");
			mService = new MemberServiceInsert();
		}
		if(command.equals("/delete.do")) {
			System.out.println("회원 제거중...");
			mService = new MemberServiceDelete();
		}
		if(command.equals("/login.do")) {
			System.out.println("로그인 테스트중...");
			mService = new MemberServiceLogin();
		}
		if(command.equals("/select.do")) {
			System.out.println("회원 전체 출력을 수행합니다.");
			mService = new MemberServiceSelect();
		}
		
		// insert, delete, login-test 할 때엔 execute() 실행만 됨 -> null값 반환
		// select 할 때엔 result로 실질적인 값이 반환될 것
		ArrayList<MemberDTO> result= mService.execute(request, response);
		if(result!=null) {
			// Controller에서만 처리할 수 있는 건, 그냥 그렇게 하면 됨
			// 다만 View의 역할이 필요할 때엔, RequestDispatcher를 사용
			//		다른 페이지에서 처리를 할 수 있도록 연결
			RequestDispatcher dis = request.getRequestDispatcher("/getList.jsp");
			dis.forward(request, response);
		}
		
		response.sendRedirect("admin_page.html");
	}
}
