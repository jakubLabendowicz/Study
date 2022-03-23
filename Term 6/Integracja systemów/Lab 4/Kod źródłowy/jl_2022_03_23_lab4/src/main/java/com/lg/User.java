package com.lg;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "users", indexes = {
        @Index(name = "loginIndex", columnList = "login")
})
public class User {
//    fields
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @Column(nullable = false, unique = true)
    private String login;
    @Column(nullable = false)
    private String password;
    private String firstName;
    private String lastName;
    @Enumerated(EnumType.STRING)
    private Sex.SexEnum sex;
    @OneToMany(fetch = FetchType.EAGER, cascade = CascadeType.ALL)
    private List<Role> roles = new ArrayList<>();
    @ManyToMany
    private List<UserGroup> userGroups = new ArrayList<>();

//    constructors
    public User() {
    }

    public User(Long id, String login, String password, String firstName, String lastName, Sex.SexEnum sex) {
        this.id = id;
        this.login = login;
        this.password = password;
        this.firstName = firstName;
        this.lastName = lastName;
        this.sex = sex;
    }

    public User(Long id, String login, String password, String firstName, String lastName, Sex.SexEnum sex, ArrayList<Role> roles) {
        this.id = id;
        this.login = login;
        this.password = password;
        this.firstName = firstName;
        this.lastName = lastName;
        this.sex = sex;
        this.roles = roles;
    }

    public User(Long id, String login, String password, String firstName, String lastName, Sex.SexEnum sex, List<Role> roles, List<UserGroup> userGroups) {
        this.id = id;
        this.login = login;
        this.password = password;
        this.firstName = firstName;
        this.lastName = lastName;
        this.sex = sex;
        this.roles = roles;
        this.userGroups = userGroups;
    }

    //    setters
    public void setId(Long id) {
        this.id = id;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setSex(Sex.SexEnum sex) {
        this.sex = sex;
    }

    public void setRoles(List<Role> roles) {
        this.roles = roles;
    }

    public void setUserGroups(List<UserGroup> userGroups) {
        this.userGroups = userGroups;
    }

    //    getters
    public Long getId() {
        return id;
    }

    public String getLogin() {
        return login;
    }

    public String getPassword() {
        return password;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public Sex.SexEnum getSex() {
        return sex;
    }

    public List<Role> getRoles() {
        return roles;
    }

    public List<UserGroup> getUserGroups() {
        return userGroups;
    }

    //    toString

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", login='" + login + '\'' +
                ", password='" + password + '\'' +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", sex=" + sex +
                ", roles=" + roles +
                ", userGroups=" + userGroups +
                '}';
    }
}
