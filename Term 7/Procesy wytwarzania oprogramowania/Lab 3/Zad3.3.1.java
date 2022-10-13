public class User {

    private double age;
    public String userName;
    protected String login;
    private String pwdHash;
    public double[] permissions;
    private boolean loggedIn = false;
  
    User(String userName, String login, String pwd) {
      this.useNname = username;
      this.login = login;
      this.pwdHash = SHA256.hash(pwd);
    }

    public void setPermissions(double[] perms) {
        permissions = perms;
    }
    
    public double[] getPermissions() {
        return permissions;
    }

    public double getPermission(int index){
        return permissions.get(index);
    }

    public String getPwdHash() {
        return this.pwdHash;
    }
}
  
public class SuperUser extends User {

    SuperUser(String userName, String login, String pwd) {
        super(userName, login, pwd);
    }

    public String getPwdHash() {
        return String.toUpperCase(this.pwdHash);
    }
}

public class Admin extends User{

    Admin (String userName, String login, String pwd){
        super(userName, “Admin” + login, SHA1.hash(pwd));
    }

    public void setPermissions(double[] perms){
        System.out.println(“Set permissions”);
        permissions = perms;
    }
    
    public String getPwdHash() {
        return String.toUpperCase(this.pwdHash);
    }
}

public class UserService {
    
    User user;

    public void logIn() {
      if (user.pwdHash = SHA256.hash(user.pwd)) {
        jakaśTamKlasa.logIn(user.username, user.getPwdHash());
        this.user.loggedIn = true;
      }
    }
  
    public void logOut() {
        jakaśTamKlasa.logOut(user.username);
        this.user.loggedIn = false;
    }

    public void logOutWithPwd() {
        jakaśTamKlasa.logOut(user.username, user.getPwdHash());
        this.user.loggedIn = false;
    }
}