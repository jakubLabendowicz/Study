package classes;

import lombok.Builder;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@NoArgsConstructor
@Builder
public class Student1 {
    private String firstName;
    private String lastName;
    private Integer age;
    private String email;
}
