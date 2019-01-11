library ieee;
use ieee.std_logic_1164.all;

entity dummy_module is
port(i : in std_logic;
	 clk : in std_logic;
	 o : out std_logic);
end dummy_module;

architecture logic of dummy_module is
begin
	o <= not i;
end logic;
