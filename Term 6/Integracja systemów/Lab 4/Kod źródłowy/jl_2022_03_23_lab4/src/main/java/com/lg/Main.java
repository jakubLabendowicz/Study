package com.lg;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.Query;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("JPA project");
        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = factory.createEntityManager();
        em.getTransaction().begin();



        User u1 = new User(null, "test_1","test_1","Andrzej", "Kowalski");
        em.persist(u1);
        User u2 = new User(null, "test_2","test_2","Andrzej", "Kowalski");
        em.persist(u2);
        User u3 = new User(null, "test_3","test_3","Andrzej", "Kowalski");
        em.persist(u3);
        User u4 = new User(null, "test_4","test_4","Andrzej", "Kowalski");
        em.persist(u4);
        User u5 = new User(null, "test_5","test_5","Andrzej", "Kowalski");
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

        em.getTransaction().commit();
        em.close();
        factory.close();

    }
}
