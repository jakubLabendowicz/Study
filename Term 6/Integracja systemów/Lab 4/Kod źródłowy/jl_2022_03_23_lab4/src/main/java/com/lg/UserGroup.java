package com.lg;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "userGroups")
public class UserGroup {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @ManyToMany
    List<User> users = new ArrayList<>();

    public UserGroup() {
    }

    public UserGroup(Long id) {
        this.id = id;
    }

    public UserGroup(Long id, List<User> users) {
        this.id = id;
        this.users = users;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public List<User> getUsers() {
        return users;
    }

    public void setUsers(List<User> users) {
        this.users = users;
    }
}
