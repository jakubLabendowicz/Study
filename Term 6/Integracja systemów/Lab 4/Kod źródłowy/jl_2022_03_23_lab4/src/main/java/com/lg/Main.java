package com.lg;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("JPA project");
        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = factory.createEntityManager();
        em.getTransaction().begin();



        User u1 = new User(null, "test_1","test_1","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);
        em.persist(u1);
        User u2 = new User(null, "test_2","test_2","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);
        em.persist(u2);
        User u3 = new User(null, "test_3","test_3","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);
        em.persist(u3);
        User u4 = new User(null, "test_4","test_4","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);
        em.persist(u4);
        User u5 = new User(null, "test_5","test_5","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);
        em.persist(u5);

        Role r1 = new Role(null, "test_1");
        em.persist(r1);
        Role r2 = new Role(null, "test_2");
        em.persist(r2);
        Role r3 = new Role(null, "test_3");
        em.persist(r3);
        Role r4 = new Role(null, "test_4");
        em.persist(r4);
        Role r5 = new Role(null, "test_5");
        em.persist(r5);

        User f1 = em.find(User.class, (long)1);
        f1.setPassword("abc");
        em.merge(f1);

        Role f2 = em.find(Role.class, (long)5);
        em.remove(f2);

        Query query = em.createQuery("SELECT u FROM User u WHERE u.lastName = 'Kowalski'");
        List<User> kowalscy = query.getResultList();
        for (User user: kowalscy) {
            System.out.println(user.toString());
        }

        Query query2 = em.createQuery("SELECT u FROM User u WHERE u.sex = 'FEMALE'");
        List<User> kobiety = query2.getResultList();
        for (User user: kobiety) {
            System.out.println(user.toString());
        }

        Role r6 = new Role(null, "test_6");
        em.persist(r6);
        Role r7 = new Role(null, "test_7");
        em.persist(r7);

        ArrayList<Role> roles = new ArrayList<Role>() {};
        roles.add(r6);
        roles.add(r7);

        User u6 = new User(null, "test_6","test_6","Andrzej", "Kowalski", Sex.SexEnum.FEMALE, roles);
        em.persist(u6);




        UserGroup g1 = new UserGroup(null);
        UserGroup g2 = new UserGroup(null);
        User u7 = new User(null, "test_7","test_7","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);
        User u8 = new User(null, "test_8","test_8","Andrzej", "Kowalski", Sex.SexEnum.FEMALE);

        ArrayList<User> users = new ArrayList<User>() {};
        users.add(u7);
        users.add(u8);
        g1.setUsers(users);
        g2.setUsers(users);

        ArrayList<UserGroup> userGroups = new ArrayList<UserGroup>() {};
        userGroups.add(g1);
        userGroups.add(g2);
        u7.setUserGroups(userGroups);
        u8.setUserGroups(userGroups);

        em.persist(g1);
        em.persist(g2);
        em.persist(u7);
        em.persist(u8);

        em.getTransaction().commit();
        em.close();
        factory.close();

    }
}
