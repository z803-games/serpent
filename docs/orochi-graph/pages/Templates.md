- Palette Color Component
	- template:: paletteColorComponent
		- <div style="width: 64px; height: 64px; display: flex; flex-direction: column; justify-content: center; align-items: center; font-size: 12px; color: white; text-shadow: 0 1px 2px black; border-radius: 4px; background-color: <%setInput: colorHex%>;">
		  id:: 6a639aed-14a0-41ac-8600-d240440f550b
		    <p style="margin: 0; font-weight: bold;">Color <%setInput: colorIndex:0,1,2,3%></p>
		    <p style="margin: 0;"><%getInput: colorHex%></p>
		  </div>
		-