

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;



entity dff_a is
    Port ( clk : in STD_LOGIC;
           d : in STD_LOGIC;
           rst : in STD_LOGIC;
           q : out STD_LOGIC);
end dff_a;

architecture Behavioral of dff_a is
    
begin
    process(clk)
    begin
        if clk'event and clk='0' then 
            if rst='1' then 
                q<='0';
            else
                q<=d;
            end if;
        end if;
    end process;

end Behavioral;
